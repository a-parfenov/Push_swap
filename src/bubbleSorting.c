/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbleSorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:32:03 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/13 16:23:45 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	bubble_sort(int *arr_num, int size)
{
	int		i;
	int		j;
	int		temp;

	i = -1;
	while (++i < size - 1)
	{
		j = size;
		while (--j > i)
		{
			if (arr_num[j - 1] > arr_num[j])
			{
				temp = arr_num[j - 1];
				arr_num[j - 1] = arr_num[j];
				arr_num[j] = temp;
			}
		}
	}
}
