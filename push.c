/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:16:52 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/14 23:27:49 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb_b(t_all *all)
{
	all->stack_b->prev->next = all->stack_a;
	all->stack_a->prev = all->stack_b->prev;
	all->stack_a->next = all->stack_b;
	all->stack_b->prev = all->stack_a;
	all->stack_b = all->stack_a;
}

void pa_a(t_all *all)
{
	all->stack_a->prev->next = all->stack_b;
	all->stack_b->prev = all->stack_a->prev;
	all->stack_b->next = all->stack_a;
	all->stack_a->prev = all->stack_b;
	all->stack_a = all->stack_b;
}

void pb(t_all *all)
{
	t_list1		*next;
	t_list1		*prev;

	if (all->stack_a == NULL)
		return ;
	next = all->stack_a->next;
	prev = all->stack_a->prev;
	if (all->stack_b)
		pb_b(all);
	else
	{
		all->stack_b = all->stack_a;
		all->stack_b->next = all->stack_b;
		all->stack_b->prev = all->stack_b;
	}
	next->prev = prev;
	prev->next = next;
	all->stack_a = next;
	if (all->command)
		ft_putendl_fd(all->command, 1);
	all->command = "pb";
	if (all->size_a == 1)
		all->stack_a = NULL;
	all->size_a--;
	all->size_b++;
}

void pa(t_all *all)
{
	t_list1		*next;
	t_list1		*prev;

	if (all->stack_b == NULL)
		return ;
	next = all->stack_b->next;
	prev = all->stack_b->prev;
	if (all->stack_a)
		pa_a(all);
	else
	{
		all->stack_a = all->stack_b;
		all->stack_a->next = all->stack_a;
		all->stack_a->prev = all->stack_a;
	}
	if (all->size_b == 1)
	{
		all->stack_b = NULL;
		// prev->next = NULL;
	}
	else
	{
		next->prev = prev;
		prev->next = next;
		all->stack_b = next;
	}
	if (all->command)
		ft_putendl_fd(all->command, 1);
	all->command = "pa";
	all->size_b--;
	all->size_a++;
}