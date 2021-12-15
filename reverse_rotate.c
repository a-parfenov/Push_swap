/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:09:10 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/15 12:33:41 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_all *all)
{
	all->stack_a = all->stack_a->prev;
	if (all->command && !ft_strncmp(all->command, "rrb", 2))
		all->command = "rrr";
	else
		if (all->command)
			ft_putendl_fd(all->command, 1);
		all->command = "rra";
}

void rrb(t_all *all)
{
	all->stack_b = all->stack_b->prev;
	if (all->command && !ft_strncmp(all->command, "rra", 2))
		all->command = "rrr";
	else
		if (all->command)
			ft_putendl_fd(all->command, 1);
		all->command = "rrb";
}

void	rrr(t_all *all)
{
	rra(all);
	rrb(all);
}
