/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:05 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/25 18:21:30 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_list1
{
	int				num;
	int				flag;
	int				order;
	struct s_list1	*next;
	struct s_list1	*prev;
}					t_list1;

typedef struct s_all
{
	struct s_list1	*stack_a;
	struct s_list1	*stack_b;

	int				min;
	int				max;
	int				med;
	
	int				flag;
	int				next;
	
	int				size_a;
	int				size_b;
	char			*command;
}					t_all;

void	sa(t_all *all);
void	sb(t_all *all);
void	ss(t_all *all);

void	pb(t_all *all);
void	pa(t_all *all);

void	ra(t_all *all);
void	rb(t_all *all);
void	rr(t_all *all);

void	rra(t_all *all);
void	rrb(t_all *all);
void	rrr(t_all *all);

void	sorting_3_num(t_all *all);
void	sorting_4_num(t_all *all);
void	sorting_5_num(t_all *all);
void	init_sorting(t_all *all);
void	bubbleSort(int *arr_num, int size);

void	sorting(t_all *all);

void	print_stacks(t_all *all);

void	ft_error(char *error);
void	validation(int argc, char const *argv[], int *arr);

#endif