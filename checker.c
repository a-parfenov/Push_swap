/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:38:10 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 21:45:11 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./gnl/get_next_line.h"

static int	check_stack(t_list1 *stack, int size)
{
	t_list1	*tmp;

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
	if (!ft_strncmp(line, "sa", 2))
		sa(all, 0);
	else if (!ft_strncmp(line, "sb", 2))
		sb(all, 0);
	else if (!ft_strncmp(line, "ss", 2))
		ss(all, 0);
	else if (!ft_strncmp(line, "pa", 2))
		pa(all, 0);
	else if (!ft_strncmp(line, "pb", 2))
		pb(all, 0);
	else if (!ft_strncmp(line, "ra", 2))
		ra(all, 0);
	else if (!ft_strncmp(line, "rb", 2))
		rb(all, 0);
	else if (!ft_strncmp(line, "rr", 2))
		rr(all, 0);
	else if (!ft_strncmp(line, "rra", 2))
		rra(all, 0);
	else if (!ft_strncmp(line, "rrb", 2))
		rrb(all, 0);
	else if (!ft_strncmp(line, "rrr", 2))
		rrr(all, 0);
	else
		all->error = 1;
}

static void	get_commands(t_all *all)
{
	char	*line;

	all->error = 0;
	line = NULL;
	while (get_next_line(0, &line))
	{
		// printf("%s", line);
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
		ft_putendl_fd("\x1b[32mOK\n", 1);
	else
		ft_putendl_fd("\x1b[31mKO\n", 1);
	// print_stacks(all);
}

int	main(int argc, char const *argv[])
{
	t_all	*all;
	int		*arr;
	int		*arr2;
	int		size_arr;

	if (argc < 2)
		return (0);
	arr = NULL;
	arr2 = NULL;
	size_arr = num_elem(argv, &arr, &arr2);
	validation(argv, &arr, &arr2, size_arr);
	if (check_arr(&arr, &arr2, size_arr))
		return (0);
	all = malloc(sizeof(t_all));
	if (!all)
	{
		free(arr);
		free(arr2);
		ft_error("0");
	}
	init(all, &arr, &arr2, size_arr);
	into_checker(all);
	clear(all);
	return (0);
}
