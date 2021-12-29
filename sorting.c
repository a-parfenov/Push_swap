/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:07:39 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/29 01:04:21 by aleslie          ###   ########.fr       */
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
	all->med = (all->max - all->min) / 2 + all->min;
}

int	maxFlag(t_list1 *stack, int size)
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
	// write(1, "+++\n", 4);
	return (max);
}

// int	check_stack(int *arr, t_all *all)  // Проверяю отсортирован ли стек
// {
// 	int	i;

// 	i = 0;
// 	while (arr[++i])
// 	{
// 		if (arr[i] < arr[i - 1])
// 			return (1);
// 	}
// 	clear(all);
// }


int check_edg_vol(t_all *all)
{
	if (all->size_b > 3)
	{
		if (all->stack_a->order == all->index
			&& all->stack_b->next->order == all->index + 1)
		{
			all->stack_a->flag = -1;
			rr(all);
			all->index++;
			pa(all);
			all->stack_a->flag = -1;
			ra(all);
			all->index++;
			return (1);
		}
		// else if (all->stack_b->order == all->index
	}
	if (all->stack_a->next->order == all->index)
	{
		sa(all);
		all->stack_a->flag = -1;
		ra(all);
		all->index++;
		return (1);
	}
	else if (all->stack_a->order == all->index)
	{
		all->stack_a->flag = -1;
		ra(all);
		all->index++;
		return (1);
	}
	return (0);
}

void	pa_(t_all *all)
{
	int	i;

	while (all->stack_b)
	{
		// if (all->size_b > 20)
		all->flag++;
		get_mid(all, all->stack_b, all->size_b);
		i = all->size_b;
		while (i--)
		{
			if (all->stack_b->order >= all->med)
			{
				pa(all);
				all->stack_a->flag = all->flag;
				if (all->stack_a->order == all->index)
				{
					all->stack_a->flag = -1;
					ra(all);
					all->index++;
				}
			}
			else
				rb(all);
		}
	}
}

void	fullSorting(t_all *all)  // Основная сортировка
{
	int	max_flag;
	int	i;

	get_mid(all, all->stack_a, all->size_a);
	i = all->size_a;
	while (i--)
	{
		if (all->stack_a->order <= all->med)
			pb(all);
		else
			ra(all);
	}
	while (all->index <= all->size_a + all->size_b)
	{
		pa_(all);
		// max_flag = maxFlag(all->stack_a, all->size_a);
		// printf("%d %d\n", all->stack_a->flag, max_flag);
		max_flag = all->stack_a->flag;
		while (all->stack_a->flag == max_flag && max_flag >= 0)
		{
			// write(1, "123\n", 4);
			// if (check_edg_vol(all))
			// 	continue ;
			pb(all);
		}
	}
}
