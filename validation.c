/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:31:39 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/25 17:47:54 by anton            ###   ########.fr       */
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

void	isdigit_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] <= '9' && str[i] >= '0') || str[i] == ' '
			|| str[i] == '\t' || str[i] == '-' || str[i] == '+'))
				ft_error("1");
		i++;
	}
}

// int	ft_isdigit1(int c)
// {
// 	return (c >= 48 && c <= 57);
// }

// void	find_val(int *arr)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (arr[++i])
// 	{
// 		while (arr[i][j++])
// 		{
// 			if (arr[i][j])
// 		}
// 		if (ft_isdigit1(arr[i]))
// 			ft_error("3");
// 		arr[i] = num;
// 	}

// }

void	validation(int argc, char const *argv[], int *arr)
{
	int		num;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (argv[++i])
	{
		isdigit_check(argv[i]);
		num = ft_atoi(argv[i]);
		k = -1;
		while (arr[++k])
		{
			if (arr[k] == num)
				ft_error("2");
		}
		arr[j++] = num;
	}
	arr[j++] = '\0';
	bubbleSort(arr, argc);
}