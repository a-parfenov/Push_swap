/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:12:58 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/29 01:14:39 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *error)
{
	(void)error;
	write(2, "ERROR: ", 7);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(1);
}

void	check_arr2(int **arr, int **arr2)
{
	if (!(*arr2))
	{
		free(*arr);
		ft_error("4");
	}
}
