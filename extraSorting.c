/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraSorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:21:44 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/31 15:24:05 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushSort(t_all *all)
{
	pa(all);
	all->stack_a->flag = -1;
	ra(all);
	all->index++;
	
}

int	check_a(t_all *all)
{
	if (all->stack_a->order == all->index)
	{
		all->stack_a->flag = -1;
		ra(all);
		all->index++;
		return (1);
	}
	if (all->stack_a->next->order == all->index)
	{
		sa(all);
		all->stack_a->flag = -1;
		ra(all);
		all->index++;
		return (1);
	}
	return (0);
}

int	check_b(t_all *all)
{
	if (all->size_b < 3)
		return (0);
	if (all->stack_b->order == all->index)
	{
		pushSort(all);
		return (1);
	}
	if (all->stack_b->next && all->stack_b->next->order == all->index
		&& all->stack_a->next->order == all->index + 1)
	{
		if (all->stack_a->next->order == all->index + 1)
			ss(all);
		else
			sb(all);
		pushSort(all);
		return (1);
	}
	if (all->stack_b->prev->order == all->index && all->size_b > 3)
	{
		rrb(all);
		pushSort(all);
		return (1);
	}
	return (0);
}

int	pre_last(t_all *all)
{
		// print_stacks(all);
	if (all->stack_b->prev->prev->order == all->index)
	{
		rrb(all);
		rrb(all);
		pushSort(all);
		return (1);
	}
	if (all->size_b > 5)
	{
		if (all->stack_b->prev->prev->prev->order == all->index)
		{
			rrb(all);
			rrb(all);
			rrb(all);
			pushSort(all);
			return (1);
		}
	}
	return (0);
}

int extraSorting(t_all *all)
{
	if (all->size_b > 3)
	{
		if (all->stack_a->order == all->index
			&& all->stack_b->next->order == all->index + 1)
		{
			all->stack_a->flag = -1;
			rr(all);
			all->index++;
			pushSort(all);
			return (1);
		}
	}
	if (check_b(all))
		return (1);
	if (all->size_b > 3)
	{
		if (pre_last(all))
			return (1);
	}
	if (check_a(all))
		return (1);
	return (0);
}

int extraSorting2(t_all *all)
{
	if (all->stack_b->order == all->index)
	{
		pushSort(all);
		return (1);
	}
	if (all->size_b > 1)
	{
		if (all->stack_b->prev->order == all->index)
		{
			rb(all);
			pushSort(all);
			return (1);
		}
		if (all->stack_a->order == all->index
			&& all->stack_b->next->order == all->index + 1)
		{
			all->stack_a->flag = -1;
			rr(all);
			all->index++;
			pushSort(all);
			return (1);
		}
		if (all->stack_a->order == all->index
			&& all->stack_b->order == all->index + 1)
		{
			all->stack_a->flag = -1;
			ra(all);
			all->index++;
			pushSort(all);
			return (1);
		}
	}
	// if (check_b(all))
	// 	return (1);
	// if (all->size_b > 3)
	// {
	// 	if (pre_last(all))
	// 	return (1);
	// }
	// if (check_a(all))
	// 	return (1);
	return (0);
}