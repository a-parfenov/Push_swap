/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:01:50 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/07 21:08:35 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v' || str == '\f'
		|| str == '\r' || str == ' ');
}

long long int	ft_atoi(const char *str)
{
	long long int	min;
	int				temp;
	size_t			i;
	size_t			count;

	i = 0;
	temp = 1;
	min = 0;
	count = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		temp = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		min = (min * 10) + (str[i++] - '0');
		count++;
	}
	return (temp * min);
}
