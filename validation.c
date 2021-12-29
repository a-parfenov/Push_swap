/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:31:39 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/29 04:14:25 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	num_elem(char const *argv[], int **arr, int **arr2)
{
	char	**arr_split;
	int		i;
	int		k;
	int		l;

	i = 0;
	l = 0;
	while (argv[++i])
	{
		isdigit_check(argv[i]);
		arr_split = ft_split(argv[i], ' ');
		k = -1;
		while (arr_split[++k])
			++l;
		k = -1;
		while (arr_split[++k])
			free(arr_split[k]);
		free(arr_split);
	}
	*arr = (int *)ft_calloc(l+1, sizeof(int));
	if (!(*arr))
		ft_error("4");
	*arr2 = (int *)ft_calloc(l+1, sizeof(int));
	check_arr2(arr, arr2);
	return (l);
}

void	validation(char const *argv[], int **arr, int **arr2, int size_arr)
{
	char	**arr_split;
	long long	num;
	int		i;
	int		j;
	int		k;
	int		l;
	
	i = 0;
	j = 0;
	while (argv[++i])
	{
		arr_split = ft_split(argv[i], ' ');
		k = -1;
		while (arr_split[++k])
		{
			num = ft_atoi(arr_split[k]);
			if (num >= MAXINT || num <= MININT)
			{
				while (arr_split[++k])
					free(arr_split[k]);
				free(arr_split);
				free(*arr);
				free(*arr2);
				ft_error("4");
			}
			l = -1;
			while ((*arr)[++l])
			{
				if ((*arr)[l] == num)
					ft_error("2"); ///// сплит arr arr2
			}
			(*arr)[j++] = num;
		}
		k = -1;
		while (arr_split[++k])
			free(arr_split[k]);
		free(arr_split);
	}
	k = -1;
	while (++k < size_arr)
		(*arr2)[k] = (*arr)[k];
	bubbleSort(*arr2, k);
	// k = -1;
	// while (++k < size_arr)
	// {
	// 	printf("*%d\n", (*arr2)[k]);
	// }
	// printf("- ***\n\n");
}