/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:22:33 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 22:04:09 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

t_node	*lstnew(int num, int order)
{
	t_node	*lst;

	lst = malloc(sizeof(t_node));
	if (lst == NULL)
		return (NULL);
	lst->prev = NULL;
	lst->next = NULL;
	lst->num = num;
	lst->order = order;
	lst->flag = 0;
	return (lst);
}

int	add_back(t_node **stack_a, t_node *list)
{
	t_node	*begin;

	if (list == NULL)
		return (1);
	begin = *stack_a;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = list;
			list->prev = begin->prev;
			list->next = begin;
			begin->prev = list;
		}
		else
		{
			begin->prev = list;
			begin->next = list;
			list->prev = begin;
			list->next = begin;
		}
	}
	else
		*stack_a = list;
	return (0);
}

void	clear(t_all *all)
{
	t_node	*temp;

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
	while (all->size_b--)
	{
		temp = all->stack_b->next;
		free(all->stack_b);
		all->stack_b = NULL;
		all->stack_b = temp;
	}
	free(all);
	exit(1);
}

static void	init_struct(t_all *all, int **arr2, int size_arr)
{
	all->size_a = size_arr;
	all->check_size = size_arr;
	all->size_b = 0;
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->command = NULL;
	all->index = 1;
	all->flag = 0;
	bubble_sort(*arr2, size_arr);
}

t_all	*init(int **arr, int **arr2, int size_arr)
{
	t_all	*all;
	int		i;
	int		j;

	all = malloc(sizeof(t_all));
	if (!all)
	{
		free(arr);
		free(arr2);
		ft_error("memory init");
	}
	init_struct(all, arr2, size_arr);
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
	return (all);
}
