/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:16:52 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/08 15:02:33 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b(t_all *all)
{
	if (all->stack_b)
	{
		all->stack_b->prev->next = all->stack_a;
		all->stack_a->prev = all->stack_b->prev;
		all->stack_a->next = all->stack_b;
		all->stack_b->prev = all->stack_a;
		all->stack_b = all->stack_a;
	}
	else
	{
		all->stack_b = all->stack_a;
		all->stack_b->next = all->stack_b;
		all->stack_b->prev = all->stack_b;
	}
}

static void	push_a(t_all *all)
{
	if (all->stack_a)
	{
		all->stack_a->prev->next = all->stack_b;
		all->stack_b->prev = all->stack_a->prev;
		all->stack_b->next = all->stack_a;
		all->stack_a->prev = all->stack_b;
		all->stack_a = all->stack_b;
	}
	else
	{
		all->stack_a = all->stack_b;
		all->stack_a->next = all->stack_a;
		all->stack_a->prev = all->stack_a;
	}
}

void	pb(t_all *all, int q)
{
	t_list1		*next;
	t_list1		*prev;

	if (all->stack_a == NULL)
		return ;
	next = all->stack_a->next;
	prev = all->stack_a->prev;
	push_b(all);
	if (all->size_a == 1)
		all->stack_a = NULL;
	else
	{
		next->prev = prev;
		prev->next = next;
		all->stack_a = next;
	}
	if (all->command && q)
		ft_putendl_fd(all->command, 1);
	all->command = "pb";
	all->size_a--;
	all->size_b++;
}

void	pa(t_all *all, int q)
{
	t_list1		*next;
	t_list1		*prev;

	if (all->stack_b == NULL)
		return ;
	next = all->stack_b->next;
	prev = all->stack_b->prev;
	push_a(all);
	if (all->size_b == 1)
		all->stack_b = NULL;
	else
	{
		next->prev = prev;
		prev->next = next;
		all->stack_b = next;
	}
	if (all->command && q)
		ft_putendl_fd(all->command, 1);
	all->command = "pa";
	all->size_b--;
	all->size_a++;
}
