/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:38:10 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 22:00:06 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include "./include//get_next_line.h"

static int	check_stack(t_node *stack, int size)
{
	t_node	*tmp;

	tmp = stack;
	while (--size)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	find_operations(t_all *all, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(all, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(all, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(all, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(all, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(all, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(all, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(all, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(all, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(all, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(all, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(all, 0);
	else
		all->error = 1;
}

static void	get_commands(t_all *all)
{
	char	*line;

	all->error = 0;
	all->count = 0;
	line = NULL;
	while (get_next_line(0, &line))
	{
		all->count++;
		find_operations(all, line);
		free(line);
		if (all->error == 1)
			return ;
	}
}

static void	into_checker(t_all *all)
{
	get_commands(all);
	if (all->error)
		write(1, "Error\n", 6);
	else if (check_stack(all->stack_a, all->size_a) && !all->size_b)
	{
		print_stacks(all);
		printf("Steps: %d\n\n", all->count);
		ft_putendl_fd("\x1b[32mOK\n", 1);
	}
	else
	{
		print_stacks(all);
		ft_putendl_fd("\x1b[31mKO\n", 1);
	}
}

int	main(int argc, char const *argv[])
{
	t_all	*all;
	int		*arr;
	int		*arr_sort;
	int		size_arr;

	if (argc < 2)
		return (0);
	arr = NULL;
	arr_sort = NULL;
	size_arr = num_elem(argv, &arr, &arr_sort);
	validation(argv, &arr, &arr_sort, size_arr);
	if (check_arr(&arr, &arr_sort, size_arr))
		return (0);
	all = init(&arr, &arr_sort, size_arr);
	into_checker(all);
	clear(all);
	return (0);
}
