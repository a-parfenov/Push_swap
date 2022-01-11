/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:50:19 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 21:58:23 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	pr_st_b(t_all *all)
{
	int		i;

	i = -1;
	write(1, "\033[1;31m--- stack b ---\033[0m\n", 28);
	if (all->stack_b)
	{
		while (++i != all->size_b)
		{
			ft_putnbr(all->stack_b->num);
			write(1, " == ", 4);
			ft_putnbr(all->stack_b->order);
			write(1, "\n", 1);
			all->stack_b = all->stack_b->next;
		}
	}
	else
		write(1, "<  Стек пуст  >\n", 25);
	write(1, "---------------\n\n", 17);
	write(1, "\033[1;32m----- *** -----\033[0m\n\n", 29);
}

void	print_stacks(t_all *all)
{
	int		i;

	i = -1;
	write(1, "\n\033[1;32m----- *** -----\033[0m\n\n", 30);
	write(1, "\033[1;31m--- stack a ---\033[0m\n", 28);
	while (all->size_a > ++i)
	{
		ft_putnbr(all->stack_a->num);
		write(1, " == ", 4);
		ft_putnbr(all->stack_a->order);
		write(1, "\n", 1);
		all->stack_a = all->stack_a->next;
	}
	write(1, "---------------\n\n", 17);
	pr_st_b(all);
}
