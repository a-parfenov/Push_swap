/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:05 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/14 23:33:16 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_list1
{
	struct s_list1	*next;
	struct s_list1	*prev;
	int				num;
}					t_list1;

typedef struct s_all
{
	struct s_list1	*stack_a;
	struct s_list1	*stack_b;

	int				min;
	int				max;
	int				med;
	int				size_a;
	int				size_b;
	char			*command;
}					t_all;

void sa(t_all *all);
void sb(t_all *all);
void pb(t_all *all);
void pa(t_all *all);

#endif