/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:30 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/15 19:29:10 by aleslie          ###   ########.fr       */
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

void	add_back(t_list1 **lst, t_list1 *new)
{
	t_list1	*begin;

	begin = *lst;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = new;
			new->prev = begin->prev;
			new->next = begin;
			begin->prev = new;
		}
		else
		{
			begin->prev = new;
			begin->next = new;
			new->prev = begin;
			new->next = begin;
		}
		
	}
	else
		*lst = new;
}

void print_stacks(t_all *all)
{
	int		i;
	
	// Печать стека а
	i = -1;
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

	
	write(1, "\n\033[1;32m----- *** -----\033[0m\n", 29);
	write(1, "\033[1;32m----- *** -----\033[0m\n\n", 29);
}

int main(int argc, char const *argv[])
{
	t_all	*all;
	int		num;
	int		i;

	if (argc < 2)
		exit(1);
	// проверка входящих переменных
	all = malloc(sizeof(t_all));
	if (!all)
		exit(1);
	all->stack_a = malloc(sizeof(t_list1));
	if (!all->stack_a)
	{
		free(all);
		exit(1);
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
		add_back(&all->stack_a, lstnew(num)); // сделать проверку создан ли лист
	}
	init_sorting(all);

	
	// pb(all);
	print_stacks(all);
	// pb(all);
	// print_stacks(all);
	// pb(all);
	// print_stacks(all);
	// ra(all);
	// print_stacks(all);
	// rb(all);
	// print_stacks(all);
	// rra(all);
	// print_stacks(all);
	// rrb(all);
	// print_stacks(all);
	// sa(all);
	// print_stacks(all);
	// pa(all);
	// print_stacks(all);
	// pa(all);
	// print_stacks(all);
	// pa(all);
	// print_stacks(all);
	
	ft_putendl_fd(all->command, 1);
	return 0;
}
