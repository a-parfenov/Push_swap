/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:05 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 21:49:38 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

# define MAXINT 2147483647
# define MININT -2147483648

typedef struct s_node
{
	int				num;
	int				flag;
	int				order;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_all
{
	struct s_node	*stack_a;
	struct s_node	*stack_b;

	int				min;
	int				max;
	int				mid;

	int				index;
	int				flag;

	int				size_a;
	int				size_b;
	int				check_size;
	char			*command;

	int				error;
	int				count;
}					t_all;

void	sa(t_all *all, int q);
void	sb(t_all *all, int q);
void	ss(t_all *all, int q);

void	pb(t_all *all, int q);
void	pa(t_all *all, int q);

void	ra(t_all *all, int q);
void	rb(t_all *all, int q);
void	rr(t_all *all, int q);

void	rra(t_all *all, int q);
void	rrb(t_all *all, int q);
void	rrr(t_all *all, int q);

t_node	*lstnew(int num, int serial_num);
int		add_back(t_node **stack_a, t_node *num);
t_all	*init(int **arr, int **arr2, int size_arr);
void	clear(t_all *all);

void	print_stacks(t_all *all);

void	full_sorting(t_all *all);

void	bubble_sort(int *arr_num, int size);

int		get_next_line(int fd, char **line);

/*
 * error_handling.c
 */

void	ft_error(char *error);
void	check_arr2(int **arr, int **arr2);
void	ft_error_2(char **arr_split, int *arr, int *arr2);
void	dup_val(int *arr, int *arr2, int num, char **arr_split);
void	arr_split_clear(char **arr_split);

/*
 * extraSorting.c
 */

int		extra_sorting(t_all *all);
void	push_sort(t_all *all);

/*
 * get_stack.c
 */

int		maxi_flag(t_node *stack, int size);
void	get_mid(t_all *all, t_node *stack, int size);
void	get_min(t_all *all, t_node *stack, int size);

/*
 * mini_sort.c
 */

void	init_sorting(t_all *all);
void	sorting_3_num(t_all *all, t_node *stack, int size);

/*
 * validation.c
 */

void	validation(char const *argv[], int **arr, int **arr2, int size_arr);
int		check_arr(int **arr, int **arr2, int size_arr);
int		num_elem(char const *argv[], int **arr, int **arr2);


#endif