/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:07:39 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 21:04:00 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_a_b(t_all *all)
{
	if (all->stack_b->order >= all->mid)
	{
		pa(all, 1);
		all->stack_a->flag = all->flag;
		if (all->stack_a->order == all->index)
		{
			all->stack_a->flag = -1;
			ra(all, 1);
			all->index++;
		}
	}
	else
	{
		if (all->stack_b->order == all->index)
			push_sort(all);
		else
			rb(all, 1);
	}
}

void	push_a(t_all *all)
{
	int	i;

	while (all->stack_b)
	{
		if (extra_sorting(all))
			continue ;
		all->flag++;
		get_mid(all, all->stack_b, all->size_b);
		i = all->size_b;
		while (i--)
			check_a_b(all);
	}
}

void	start_sort(t_all *all, int i)
{
	while (all->size_b <= all->mid && i--)
	{
		if (all->stack_a->order <= all->mid)
		{
			pb(all, 1);
			if (all->stack_b->order == all->index
				&& all->size_a + all->size_b > 20)
			{
				all->stack_b->flag = -2;
				if (all->size_b > 1)
					rb(all, 1);
				all->index++;
			}
		}
		else
			ra(all, 1);
	}
	while (all->stack_b->prev->flag == -2)
		rrr(all, 1);
	while (all->stack_b->flag == -2)
	{
		pa(all, 1);
		all->stack_a->flag = -1;
		ra(all, 1);
	}
}

void	full_sorting(t_all *all)
{
	int	max_flag;

	get_mid(all, all->stack_a, all->size_a);
	start_sort(all, all->size_a);
	while (all->index <= all->check_size)
	{
		push_a(all);
		max_flag = maxi_flag(all->stack_a, all->size_a);
		while (all->stack_a->flag == max_flag)
		{
			if (extra_sorting(all))
				continue ;
			pb(all, 1);
		}
	}
}
