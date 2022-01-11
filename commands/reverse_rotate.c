/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:09:10 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 21:59:14 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	rra(t_all *all, int q)
{
	if (all->size_a <= 1)
		return ;
	all->stack_a = all->stack_a->prev;
	if (all->command && !ft_strcmp(all->command, "rrb\n"))
		all->command = "rrr";
	else
		if (all->command && q)
			ft_putendl_fd(all->command, 1);
		all->command = "rra";
}

void	rrb(t_all *all, int q)
{
	if (all->size_b <= 1)
		return ;
	all->stack_b = all->stack_b->prev;
	if (all->command && !ft_strcmp(all->command, "rra\n"))
		all->command = "rrr";
	else
		if (all->command && q)
			ft_putendl_fd(all->command, 1);
		all->command = "rrb";
}

void	rrr(t_all *all, int q)
{
	if (all->size_a <= 1 && all->size_b <= 1)
		return ;
	rra(all, q);
	rrb(all, q);
}
