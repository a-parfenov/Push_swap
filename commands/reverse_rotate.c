/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:09:10 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 21:41:19 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all *all, int q)
{
	if (all->size_a <= 1)
		return ;
	// printf("*** rra\n");
	all->stack_a = all->stack_a->prev;
	if (all->command && !ft_strncmp(all->command, "rrb", 3))
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
	// printf("*** rrb\n");
	all->stack_b = all->stack_b->prev;
	if (all->command && !ft_strncmp(all->command, "rra", 3))
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
	// printf("*** rrr\n");
	rra(all, q);
	rrb(all, q);
}
