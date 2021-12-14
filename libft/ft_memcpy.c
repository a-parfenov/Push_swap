/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:09:45 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/14 23:09:47 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char	*array1;
	unsigned char	*array2;
	size_t			i;

	i = 0;
	if ((void *) 0 == dst && (void *) 0 == src)
		return (dst);
	array1 = (unsigned char *)dst;
	array2 = (unsigned char *)src;
	while (i < n)
	{
		array1[i] = array2[i];
		++i;
	}
	return ((void *)dst);
}
