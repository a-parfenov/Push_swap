/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:07:39 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/25 22:29:31 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_all *all)
{
	int		i;

	all->next = 1;
	all->flag = 0;
	i = all->size_a;
	while (i--)
	{
		// printf("%d\n", all->size_a);
		if (all->stack_a->num <= all->med)
			pb(all);
		else
			ra(all);
	}
	print_stacks(all);
	while (all->stack_b)
	{
		all->max = all->med;
		all->med = (all->max - all->next) / 2 + all->next;
		all->flag++;
		if (all->size_b == 3)
		{
			i = 3;
			while (i--)
			{
				sorting_3_num(all);
				pa(all);
				all->stack_a->flag = all->flag;
				if (all->stack_a->order == all->next)
				{
					all->next++;
					ra(all);
				}
			}
		}
		else
		{
			i = all->size_b;
			while (i--)
			{
				// printf("%d\n", all->med);
				if (all->stack_b->num <= all->med)
					pa(all);
				else
				{
					print_stacks(all);
					rb(all);
				}
				all->stack_a->flag = all->flag;
				if (all->stack_a->order == all->next)
				{
					all->next++;
					ra(all);
					// write(1, "111\n", 4);
				}
			}
		}
	}
	print_stacks(all);
}