/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:30 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/29 09:42:09 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list1	*lstnew(int num, int j)
{
	t_list1	*lst;

	lst = malloc(sizeof(t_list1));
	if (lst == NULL)
		return (NULL);
	lst->prev = NULL;
	lst->next = NULL;
	lst->num = num;
	lst->order = j;
	lst->flag = 0;
	return (lst);
}

int	add_back(t_list1 **stack_a, t_list1 *num)
{
	t_list1	*begin;

	if (num == NULL)
		return (1);
	begin = *stack_a;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = num;
			num->prev = begin->prev;
			num->next = begin;
			begin->prev = num;
		}
		else
		{
			begin->prev = num;
			begin->next = num;
			num->prev = begin;
			num->next = begin;
		}
	}
	else
		*stack_a = num;
	return (0);
}

void	clear(t_all *all)
{
	t_list1	*temp;

	if (!all->stack_a)
		return ;
	all->stack_a->prev->next = NULL;
	while (all->stack_a)
	{
		temp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = temp;
	}
	free(all);
	exit(1);
}

void	init(t_all *all, int **arr, int **arr2, int size_arr)
{
	int	i;
	int	j;

	all->size_a = size_arr;
	all->size_b = 0;
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->command = NULL;
	all->index = 1;
	all->flag = 0;
	i = -1;
	while (++i < all->size_a)
	{
		j = 0;
		while ((*arr)[i] != (*arr2)[j])
			++j;
		if (add_back(&all->stack_a, lstnew((*arr)[i], j + 1)))
			clear(all);
	}
	free(*arr);
	free(*arr2);
}

int	check_arr(int **arr, int **arr2, int size_arr)
{
	int	i;
	
	
	if (size_arr == 1)
	{
		free(*arr);
		free(*arr2);
		return (0);
	}
	i = -1;
	while (++i < size_arr)
	{
		// printf("*%d %d\n", (*arr)[i], (*arr2)[i]);
		if ((*arr)[i] != (*arr2)[i])
			return (0);
	}
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_all	*all;
	int		*arr;
	int		*arr2;
	int		size_arr;

	if (argc < 2)
		ft_error("argv");
	arr = NULL;
	arr2 = NULL;
	size_arr = num_elem(argv, &arr, &arr2);
	validation(argv, &arr, &arr2, size_arr);
	if (check_arr(&arr, &arr2, size_arr))
	{
		free(arr);
		free(arr2);
		return (0);
	}
	all = malloc(sizeof(t_all));
	if (!all)
		ft_error("0");
	all->stack_a = malloc(sizeof(t_list1));
	if (!all->stack_a)
	{
		free(all);
		ft_error("0");
	}
	init(all, &arr, &arr2, size_arr);
	init_sorting(all);
	ft_putendl_fd(all->command, 1);
	print_stacks(all);
	clear(all);
	return (0);
}
