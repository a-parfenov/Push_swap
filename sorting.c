/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:07:39 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/31 15:29:51 by aleslie          ###   ########.fr       */
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


void	push_a(t_all *all)
{
	while (all->stack_b)
	{
		if (extraSorting(all))
			continue ;
		all->flag++;
		get_mid(all, all->stack_b, all->size_b);
		while (all->size_b > (all->med - all->min))
		{
			if (all->stack_b->order >= all->med)
			{
				// if (extraSorting(all))
				// 	continue ;
				// printf("+++++++\n");
				// print_stacks(all);
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

void	startSort(t_all *all, int i)
{
	while (all->size_b <= all->med && i--)
	{
		if (all->stack_a->order <= all->med)
		{
			pb(all);
			if (all->stack_b->order == all->index && all->size_a + all->size_b > 20)
			{
				all->stack_b->flag = -2;
				if (all->size_b > 1)
					rb(all);
				all->index++;
			}
		}
		else
			ra(all);
	}
	while (all->stack_b->prev->flag == -2)
		rrr(all);
	while (all->stack_b->flag == -2)
	{
		pa(all);
		all->stack_a->flag = -1;
		ra(all);
	}
}

void	fullSorting(t_all *all)
{
	int	max_flag;

	get_mid(all, all->stack_a, all->size_a);
	startSort(all, all->size_a);
	while (all->index <= all->checkSize)
	{
		// write(1, "***\n", 4);
		push_a(all);
		max_flag = maxFlag(all->stack_a, all->size_a);
		while (all->stack_a->flag == max_flag)
		{
			// write(1, "123\n", 4);
			// if (extraSorting(all))
			// 	continue ;
			pb(all);
		}
	}
}
