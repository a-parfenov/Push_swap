/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:06:14 by aleslie           #+#    #+#             */
/*   Updated: 2021/11/11 18:49:12 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *) malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, count * size);
	return (mem);
}

/* Топовый вариант */
// void *calloc(size_t count, size_t size) {
// 	size_t		tempos;
// 	void		*tmp;

// 	if (__builtin_mul_overflow (count, size, &tempos)) 
// 	{
// 		errno = ENOMEM; // Идентификация ошибок
// 		return (0);
// 	}
// 	if ((tmp = malloc(tempos)) == 0)
// 		return (0);
// 	ft_memset(tmp, 0, tempos);
// 	return (tmp);
// }

