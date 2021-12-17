/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:30 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/17 20:56:37 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list1	*lstnew(int num)
{
	t_list1	*lst;

	lst = malloc(sizeof(t_list1));
	if (lst == NULL)
		return (NULL);
	lst->prev = NULL;
	lst->next = NULL;
	lst->num = num;
	return (lst);
}

int	add_back(t_list1 **stack_a, t_list1 *num)
{
	t_list1	*begin;

	if (num == NULL)
		return (1);
	begin = *stack_a;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = num;
			num->prev = begin->prev;
			num->next = begin;
			begin->prev = num;
		}
		else
		{
			begin->prev = num;
			begin->next = num;
			num->prev = begin;
			num->next = begin;
		}
	}
	else
		*stack_a = num;
	return (0);
}

void print_stacks(t_all *all)
{
	int		i;
	
	// Печать стека а
	i = -1;
	write(1, "\n\033[1;32m----- *** -----\033[0m\n\n", 30);
	write(1, "\033[1;31m--- stack a ---\033[0m\n", 28);
	while (all->size_a > ++i)
	{
		ft_putnbr(all->stack_a->num);
		write(1, "\n", 1);
		all->stack_a = all->stack_a->next;
	}
	write(1, "---------------\n", 16);
	write(1, "\n", 1);
	
	// Печать стека b
	i = -1;
	write(1, "\033[1;31m--- stack b ---\033[0m\n", 28);
	if (all->stack_b)
	{
		while (++i != all->size_b)
		{
			ft_putnbr(all->stack_b->num);
			write(1, "\n", 1);
			all->stack_b = all->stack_b->next;
		}
	}
	else
		write(1, "<  Стек пуст  >\n", 25);
	write(1, "---------------\n", 16);

	
	write(1, "\033[1;32m----- *** -----\033[0m\n\n", 29);
}

void	clear(t_all *all)
{
	t_list1	*temp;

	if (!all->stack_a)
		return ;
	all->stack_a->prev->next = NULL;
	while (all->stack_a)
	{
		temp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = temp;
	}
	free(all);
	exit(1);
}

int main(int argc, char const *argv[])
{
	t_all	*all;
	int		num;
	int		i;

	if (argc < 2)
		ft_error("argv");
	validation(argc, argv); // check
	all = malloc(sizeof(t_all));
	if (!all)
		ft_error("0");
	all->stack_a = malloc(sizeof(t_list1));
	if (!all->stack_a)
	{
		free(all);
		ft_error("0");
	}
	all->size_a = argc - 1;
	all->size_b = 0;
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->command = NULL;
	i = 0;
	while (argv[++i])
	{
		num = ft_atoi(argv[i]);
		if (add_back(&all->stack_a, lstnew(num)))
			clear(all);
	}
	init_sorting(all);
	
	ft_putendl_fd(all->command, 1);
	print_stacks(all);
	clear(all);
	return 0;
}
