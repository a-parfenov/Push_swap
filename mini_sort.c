/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:56:47 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/29 19:16:45 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubbleSort(int *arr_num, int size)
{
	int		i;
	int		j;
	int		temp;

	i = -1;
	while (++i < size - 1)
	{
		j = size;
		while (--j > i)
		{
			if (arr_num[j - 1] > arr_num[j])
			{
				temp = arr_num[j - 1];
				arr_num[j - 1] = arr_num[j];
				arr_num[j] = temp;
			}
		}
	}
}

void	sorted_arr(int *arr, t_list1 *stack, int size)
{
	arr[0] = stack->num;
	arr[1] = stack->next->num;
	arr[2] = stack->next->next->num;
	arr[3] = '\0';
	bubbleSort(arr, size);
}

void	sorting_3_num(t_all *all, t_list1 *stack, int size)
{
	int		arr[4];
	int		min;
	int		max;
	int		med;

	sorted_arr(arr, stack, size);
	min = arr[0];
	max = arr[all->size_a - 1];
	med = arr[(all->size_a) / 2];
	if (all->stack_a->num == max)
		ra(all);
	if (all->stack_a->num == med)
	{
		if (all->stack_a->next->num == max)
			rra(all);
		else
			sa(all);
		return ;
	}
	if (all->stack_a->next->num == max)
	{
		rra(all);
		sa(all);
	}
}

int	find_path(int min, t_list1 *stack)
{
	int		i;
	t_list1	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->order == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	mini_sorting(t_all *all)
{
	// print_stacks(all);
	while (all->size_a > 3)
	{
		get_min(all, all->stack_a, all->size_a);
		while (all->stack_a->order != all->min)
		{
			if (find_path(all->min, all->stack_a) <= 3)
				ra(all);
			else
				rra(all);
		}
		pb(all);
		// print_stacks(all);
	}
	sorting_3_num(all, all->stack_a, all->size_a);
	// print_stacks(all);
	while (all->size_b)
		pa(all);
}

void	init_sorting(t_all *all)
{
	if (all->size_a == 2)
	{
		if (all->stack_a->num > all->stack_a->next->num)
			sa(all);
	}
	else if (all->size_a == 3)
		sorting_3_num(all, all->stack_a, all->size_a);
	else if (all->size_a <= 5)
		mini_sorting(all);
	else if (all->size_a > 5)
		fullSorting(all);
}
