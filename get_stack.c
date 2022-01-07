/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:32:34 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 20:58:52 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(t_all *all, t_list1 *stack, int size)
{
	t_list1	*tmp;
	int		max;
	int		i;

	tmp = stack;
	max = tmp->order;
	i = -1;
	while (++i != size)
	{
		if (max < tmp->order)
			max = tmp->order;
		tmp = tmp->next;
	}
	all->max = max;
}

void	get_min(t_all *all, t_list1 *stack, int size)
{
	t_list1	*tmp;
	int		min;
	int		i;

	tmp = stack;
	min = tmp->order;
	i = -1;
	while (++i != size)
	{
		if (min > tmp->order)
			min = tmp->order;
		tmp = tmp->next;
	}
	all->min = min;
}

void	get_mid(t_all *all, t_list1 *stack, int size)
{
	get_max(all, stack, size);
	get_min(all, stack, size);
	all->mid = (all->max - all->min) / 2 + all->min;
}

int	maxi_flag(t_list1 *stack, int size)
{
	int		max;
	t_list1	*tmp;

	max = 0;
	tmp = stack;
	while (tmp && size--)
	{
		if (tmp->flag > max && tmp->flag >= 0)
			max = tmp->flag;
		tmp = tmp->next;
	}
	return (max);
}
