/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:54:30 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/08 15:02:13 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ra: rotate a - shift up all elements of stack a by 1.
 		The first element becomes the last one;
 * rb: rotate b - shift up all elements of stack b by 1.
 		The first element becomes the last one;
 * rr: ra and rb at the same time.
 */

void	ra(t_all *all, int q)
{
	if (all->size_a <= 1)
		return ;
	all->stack_a = all->stack_a->next;
	if (all->command && !ft_strcmp(all->command, "rb\n"))
		all->command = "rr";
	else
		if (all->command && q)
			ft_putendl_fd(all->command, 1);
		all->command = "ra";
}

void	rb(t_all *all, int q)
{
	if (all->size_b <= 1)
		return ;
	all->stack_b = all->stack_b->next;
	if (all->command && !ft_strcmp(all->command, "ra\n"))
		all->command = "rr";
	else
		if (all->command && q)
			ft_putendl_fd(all->command, 1);
		all->command = "rb";
}

void	rr(t_all *all, int q)
{
	if (all->size_a <= 1 && all->size_b <= 1)
		return ;
	ra(all, q);
	rb(all, q);
}
