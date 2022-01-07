/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:30 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 20:55:37 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * For printing stacks: print_stacks(all);
 */

int	main(int argc, char const *argv[])
{
	t_all	*all;
	int		*arr;
	int		*arr2;
	int		size_arr;

	if (argc < 2)
		return (0);
	arr = NULL;
	arr2 = NULL;
	size_arr = num_elem(argv, &arr, &arr2);
	validation(argv, &arr, &arr2, size_arr);
	if (check_arr(&arr, &arr2, size_arr))
		return (0);
	all = malloc(sizeof(t_all));
	if (!all)
	{
		free(arr);
		free(arr2);
		ft_error("0");
	}
	init(all, &arr, &arr2, size_arr);
	init_sorting(all);
	ft_putendl_fd(all->command, 1);
	clear(all);
	return (0);
}
