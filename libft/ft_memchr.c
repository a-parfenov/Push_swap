/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:09:32 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/14 23:09:34 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		return (0);
	while (i < n)
	{
		if (*((unsigned char *)arr + i) == (unsigned char)c)
			return ((unsigned char *)arr + i);
		++i;
	}
	return (NULL);
}
