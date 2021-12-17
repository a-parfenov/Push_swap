/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:56:47 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/17 19:33:57 by aleslie          ###   ########.fr       */
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

void sorted_arr(t_all *all, int *arr)
{
	arr[0] = all->stack_a->num;
	arr[1] = all->stack_a->next->num;
	arr[2] = all->stack_a->next->next->num;
	arr[3] = '\0';
	bubbleSort(arr, all->size_a);
}

void	sorting_3_num(t_all *all)
{
	int		arr[4];
	int		min;
	int		max;
	int		med;

	sorted_arr(all, arr);
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

void	mini_sorting(t_all *all, int i, int j)
{
	while (all->size_a > 3)
		pb(all);
	sorting_3_num(all);
	if (all->size_b == 2)
	{
		if (all->stack_b->num > all->stack_b->next->num)
			sb(all);
	}
	while (all->size_b)
	{
		if (all->stack_b->num < all->stack_a->num)
			pa(all);
		else if (all->stack_b->num > all->stack_a->num)
		{
			ra(all);
			j++;
		}
		if (++i == all->size_a)
			pa(all);
	}
	while (j--)
		rra(all);
}

void	init_sorting(t_all *all)
{
	if (all->size_a == 1)
		return ;
	else if (all->size_a == 2)
	{
		if (all->stack_a->num > all->stack_a->next->num)
			sa(all);
	}
	else if (all->size_a == 3)
		sorting_3_num(all);
	else if (all->size_a <= 5)
		mini_sorting(all, 0, 0);
	else if (all->size_a > 5)
		sorting(all);
}
