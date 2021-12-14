/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:07 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/14 17:11:25 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_all *all)
{
	int temp;

	if (all->stack_a == NULL || all->stack_a->next == NULL)
		return ;
	temp = all->stack_a->num;
	all->stack_a->num = all->stack_a->next->num;
	all->stack_a->next->num = temp;
	if (all->command && !ft_strncmp(all->command, "sb", 2))
		all->command = "ss";
	else
		if (all->command)
			ft_putendl_fd(all->command, 1);
		all->command = "sa";
}

void sb(t_all *all)
{
	int temp;

	if (all->stack_b == NULL || all->stack_b->next == NULL)
		return ;
	temp = all->stack_b->num;
	all->stack_b->num = all->stack_b->next->num;
	all->stack_b->next->num = temp;
	if (all->command && !ft_strncmp(all->command, "sa", 2))
		all->command = "ss";
	else
		if (all->command)
			ft_putendl_fd(all->command, 1);
		all->command = "sb";
}

