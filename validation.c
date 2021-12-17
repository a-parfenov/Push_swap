/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:31:39 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/17 19:19:15 by aleslie          ###   ########.fr       */
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
			{
				// ft_error("Error_1");
				write(1, "ERROR\n", 6);
				exit(1);
			}
		i++;
	}
}

// void	find_val(int argc, char const *argv[], t_all *all)
// {
// 	int		arr[argc];
// 	int		num;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (argv[++i] && i < argc)
// 	{
// 		num = ft_atoi(argv[i]);
// 		arr[j++] = num;
// 	}
// 	arr[j++] = '\0';
// 	bubbleSort(arr, argc - 1);
// 	// for (int i = 0; i < argc - 1; i++)
// 	// 	printf("%d\n", arr[i]);
// 	all->min = arr[0];
// 	all->max = arr[argc - 2];
// 	all->med = arr[(argc - 1) / 2];
// 	// write(1, "-----\n", 6);
// 	// printf("|%d\n", all->min);
// 	// printf("|%d\n", all->max);
// 	// printf("|%d\n", all->med);
// }

void	validation(int argc, char const *argv[])
{
	int		arr[argc];
	int		num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[++i] && i < argc)
	{
		// isdigit_check(argv[i]);
		num = ft_atoi(argv[i]);
		arr[j++] = num;
	}
	arr[j++] = '\0';
	// find_val(argc, argv, all);
	// printf("{%d}\n", *arr);
}