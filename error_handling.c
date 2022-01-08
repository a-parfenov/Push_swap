/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:12:58 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/08 16:24:21 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *error)
{
	(void)error;
	write(2, "Error: ", 7);
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

void	ft_error_2(char **arr_split, int *arr, int *arr2)
{
	int	k;

	k = -1;
	while (arr_split[++k])
		free(arr_split[k]);
	free(arr_split);
	free(arr);
	free(arr2);
	ft_error("5");
}

void	dup_val(int *arr, int *arr2, int num, char **arr_split)
{
	int	i;
	int	k;

	i = -1;
	while (arr[++i])
	{
		if (arr[i] == num)
		{
			k = -1;
			arr_split_clear(arr_split);
			free(arr);
			free(arr2);
			ft_error("6");
		}
	}
}

void	arr_split_clear(char **arr_split)
{
	int	k;

	k = -1;
	while (arr_split[++k])
		free(arr_split[k]);
	free(arr_split);
}
