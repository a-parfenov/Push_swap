/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:56:47 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 21:58:28 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

static void	sorted_arr(int *arr, t_node *stack, int size)
{
	arr[0] = stack->num;
	arr[1] = stack->next->num;
	arr[2] = stack->next->next->num;
	arr[3] = '\0';
	bubble_sort(arr, size);
}

void	sorting_3_num(t_all *all, t_node *stack, int size)
{
	int		arr[4];
	int		min;
	int		max;
	int		med;

	sorted_arr(arr, stack, size);
	min = arr[0];
	max = arr[all->size_a - 1];
	med = arr[(all->size_a) / 2];
	if (all->stack_a->num == max)
		ra(all, 1);
	if (all->stack_a->num == med)
	{
		if (all->stack_a->next->num == max)
			rra(all, 1);
		else
			sa(all, 1);
		return ;
	}
	if (all->stack_a->next->num == max)
	{
		rra(all, 1);
		sa(all, 1);
	}
}

int	find_path(int min, t_node *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->order == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	mini_sorting(t_all *all)
{
	while (all->size_a > 3)
	{
		get_min(all, all->stack_a, all->size_a);
		while (all->stack_a->order != all->min)
		{
			if (find_path(all->min, all->stack_a) <= 3)
				ra(all, 1);
			else
				rra(all, 1);
		}
		pb(all, 1);
	}
	sorting_3_num(all, all->stack_a, all->size_a);
	while (all->size_b)
	{
		pa(all, 1);
	}
}

void	init_sorting(t_all *all)
{
	if (all->size_a == 2)
	{
		if (all->stack_a->num > all->stack_a->next->num)
			sa(all, 1);
	}
	else if (all->size_a == 3)
		sorting_3_num(all, all->stack_a, all->size_a);
	else if (all->size_a <= 5)
		mini_sorting(all);
	else if (all->size_a > 5)
		full_sorting(all);
	ft_putendl_fd(all->command, 1);
}
