/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:01:50 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/14 23:02:21 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v' || str == '\f'
		|| str == '\r' || str == ' ');
}

static size_t	ft_main(size_t count, long int temp, long int min)
{
	if (count >= 11)
	{
		if (temp == -1)
			return (0);
		else
			return (-1);
	}
	return (temp * min);
}

int	ft_atoi(const char *str)
{
	long int	min;
	long int	temp;
	size_t		i;
	size_t		count;

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
	return (ft_main(count, temp, min));
}
