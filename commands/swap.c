/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:07 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 21:41:42 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *all, int q)
{
	int	temp;

	if (1 < all->size_a)
	{
		if (all->stack_a == NULL || all->stack_a->next == NULL)
			return ;
		// printf("*** sa\n");
		temp = all->stack_a->num;
		all->stack_a->num = all->stack_a->next->num;
		all->stack_a->next->num = temp;
		temp = all->stack_a->order;
		all->stack_a->order = all->stack_a->next->order;
		all->stack_a->next->order = temp;
		temp = all->stack_a->flag;
		all->stack_a->flag = all->stack_a->next->flag;
		all->stack_a->next->flag = temp;
		if (all->command && !ft_strncmp(all->command, "sb", 2))
			all->command = "ss";
		else
		{
			if (all->command && q)
				ft_putendl_fd(all->command, 1);
			all->command = "sa";
		}
	}
}

void	sb(t_all *all, int q)
{
	int	temp;

	if (1 < all->size_b)
	{
		if (all->stack_b == NULL || all->stack_b->next == NULL)
			return ;
		// printf("*** sb\n");
		temp = all->stack_b->num;
		all->stack_b->num = all->stack_b->next->num;
		all->stack_b->next->num = temp;
		temp = all->stack_b->order;
		all->stack_b->order = all->stack_b->next->order;
		all->stack_b->next->order = temp;
		temp = all->stack_b->flag;
		all->stack_b->flag = all->stack_b->next->flag;
		all->stack_b->next->flag = temp;
		if (all->command && !ft_strncmp(all->command, "sa", 2))
			all->command = "ss";
		else
		{
			if (all->command && q)
				ft_putendl_fd(all->command, 1);
			all->command = "sb";
		}
	}
}	

void	ss(t_all *all, int q)
{
	if (1 < all->size_a && 1 < all->size_b)
	{
		// printf("*** ss\n");
		sa(all, q);
		sb(all, q);
	}
}
