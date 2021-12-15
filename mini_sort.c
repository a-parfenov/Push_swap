/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:56:47 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/15 23:39:59 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3_num(t_all *all)
{
	if (all->stack_a->next->next->num < all->stack_a->next->num
			&& all->stack_a->next->next->num > all->stack_a->num)
	{
		rra(all);
		sa(all);
	}
	if (all->stack_a->num > all->stack_a->next->num)
		sa(all);
	if (all->stack_a->num > all->stack_a->next->next->num)
		rra(all);
}

void	sorting_4_num(t_all *all)
{
	int	i;

	pb(all);
	sorting_3_num(all);
	i = 0;
	while (all->stack_a->num < all->stack_b->num && all->size_a >= ++i)
		ra(all);
	pa(all);
	while (i--)
		rra(all);
	if (all->stack_a->num > all->stack_a->next->num)
		ra(all);
}

void	sorting_5_num(t_all *all)
{
	int	i;

	pb(all);
	sorting_4_num(all);
	i = 0;
	while (all->stack_a->num < all->stack_b->num && all->size_a >= ++i)
		ra(all);
	pa(all);
	while (i--)
		rra(all);
	if (all->stack_a->num > all->stack_a->next->num)
		ra(all);
}

void	mini_sorting(t_all *all)
{
	// int	i = 0;

	while (all->size_a > 3)
		pb(all);
	sorting_3_num(all);
	// if (all->size_b == 2 && )
	// 	sb(all);
	// else if (all->size_b == 3)
	// 	sorting_3_num(all);
	
}

void	init_sorting(t_all *all)
{
	if (all->size_a == 2)
	{
		if (all->stack_a->num > all->stack_a->next->num)
			sa(all);
	}
	else if (all->size_a == 3)
		sorting_3_num(all);
	else if (all->size_a <= 6)
		mini_sorting(all);
	// else if (all->size_a > 6)
	// 	sorting(all);
}
