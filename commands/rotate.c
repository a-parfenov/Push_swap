/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:54:30 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/25 18:58:33 by anton            ###   ########.fr       */
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

void	ra(t_all *all)
{
	all->stack_a = all->stack_a->next;
	if (all->command && !ft_strncmp(all->command, "rb", 2))
		all->command = "rr";
	else
		if (all->command)
			ft_putendl_fd(all->command, 1);
		all->command = "ra";
}

void	rb(t_all *all)
{
	all->stack_b = all->stack_b->next;
	if (all->command && !ft_strncmp(all->command, "ra", 2))
		all->command = "rr";
	else
		if (all->command)
			ft_putendl_fd(all->command, 1);
		all->command = "rb";
}

void	rr(t_all *all)
{
	ra(all);
	rb(all);
}
