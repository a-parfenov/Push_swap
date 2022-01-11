/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraSorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:21:44 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 21:58:36 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	push_sort(t_all *all)
{
	pa(all, 1);
	all->stack_a->flag = -1;
	ra(all, 1);
	all->index++;
}

static int	pre_last(t_all *all)
{
	if (all->stack_b->prev->prev->order == all->index)
	{
		rrb(all, 1);
		rrb(all, 1);
		push_sort(all);
		return (1);
	}
	if (all->size_b > 5)
	{
		if (all->stack_b->prev->prev->prev->order == all->index)
		{
			rrb(all, 1);
			rrb(all, 1);
			rrb(all, 1);
			push_sort(all);
			return (1);
		}
	}
	return (0);
}

static int	down_num_b(t_all *all)
{
	if (all->size_b > 3)
	{
		if (all->stack_b->prev->order == all->index)
		{
			rrb(all, 1);
			push_sort(all);
			return (1);
		}
		if (pre_last(all))
			return (1);
	}
	return (0);
}

int	extra_sorting(t_all *all)
{
	if (all->stack_a->order == all->index)
	{
		all->stack_a->flag = -1;
		ra(all, 1);
		all->index++;
		return (1);
	}
	if (all->stack_b && all->stack_b->order == all->index)
	{
		push_sort(all);
		return (1);
	}
	if (all->stack_b && all->stack_b->next->order == all->index)
	{
		sb(all, 1);
		push_sort(all);
		return (1);
	}
	if (down_num_b(all))
		return (1);
	return (0);
}
