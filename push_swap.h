/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:05 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/29 04:46:09 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

# define MAXINT 2147483647
# define MININT -2147483648

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
	
	int				index;
	int				flag;
	
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

void	sorting_3_num(t_all *all, t_list1 *stack, int size);
void	init_sorting(t_all *all);
void	bubbleSort(int *arr_num, int size);
void	get_mid(t_all *all, t_list1 *stack, int size);
int		check_sort_stack(t_list1 *stack);

void	fullSorting(t_all *all);

void	print_stacks(t_all *all);
void	clear(t_all *all);

void	ft_error(char *error);
void	check_arr2(int **arr, int **arr2);

void	validation(char const *argv[], int **arr, int **arr2, int size_arr);
void	get_min(t_all *all, t_list1 *stack, int size);
int		num_elem(char const *argv[], int **arr, int **arr2);

#endif