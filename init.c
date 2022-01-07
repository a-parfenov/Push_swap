/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:22:33 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 21:06:39 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list1	*lstnew(int num, int serial_num)
{
	t_list1	*lst;

	lst = malloc(sizeof(t_list1));
	if (lst == NULL)
		return (NULL);
	lst->prev = NULL;
	lst->next = NULL;
	lst->num = num;
	lst->order = serial_num;
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
	all->check_size = size_arr;
	all->size_b = 0;
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->command = NULL;
	all->index = 1;
	all->flag = 0;
	bubble_sort(*arr2, size_arr);
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
