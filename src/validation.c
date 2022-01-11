/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:31:39 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 21:58:07 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	check_arr(int **arr, int **arr2, int size_arr)
{
	int	i;

	if (size_arr == 1)
	{
		free(*arr);
		free(*arr2);
		return (1);
	}
	i = -1;
	while (++i < size_arr - 1)
	{
		if ((*arr)[i] > (*arr)[i + 1])
			return (0);
	}
	free(*arr);
	free(*arr2);
	return (1);
}

static void	isdigit_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] <= '9' && str[i] >= '0') || str[i] == ' '
				|| str[i] == '\t' || str[i] == '-' || str[i] == '+'))
			ft_error("the arguments must be int");
		i++;
	}
}

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
	*arr = (int *)ft_calloc(l + 1, sizeof(int));
	if (!(*arr))
		ft_error("memory arr");
	*arr2 = (int *)ft_calloc(l + 1, sizeof(int));
	check_arr2(arr, arr2);
	return (l);
}

void	validation(char const *argv[], int **arr, int **arr2, int size_arr)
{
	char		**arr_split;
	long long	num;
	int			i;
	int			j;
	int			k;

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
				ft_error_2(arr_split, *arr, *arr2);
			dup_val(*arr, *arr2, num, arr_split);
			(*arr)[j++] = num;
		}
		arr_split_clear(arr_split);
	}
	k = -1;
	while (++k < size_arr)
		(*arr2)[k] = (*arr)[k];
}
