/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:30 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/11 21:58:20 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

/*
 * For printing stacks: print_stacks(all);
 */

int	main(int argc, char const *argv[])
{
	t_all	*all;
	int		*arr;
	int		*arr_sort;
	int		size_arr;

	if (argc < 2)
		return (0);
	arr = NULL;
	arr_sort = NULL;
	size_arr = num_elem(argv, &arr, &arr_sort);
	validation(argv, &arr, &arr_sort, size_arr);
	if (check_arr(&arr, &arr_sort, size_arr))
		return (0);
	all = init(&arr, &arr_sort, size_arr);
	init_sorting(all);
	clear(all);
	return (0);
}
