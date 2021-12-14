/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:11:39 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/14 23:11:41 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		if (haystack[i] == needle[k])
		{
			while (needle[k] && i + k < len && haystack[i + k] == needle[k])
			{
				if (needle[k + 1] == '\0')
					return ((char *)&haystack[i]);
				++k;
			}
		}
		++i;
	}
	return (NULL);
}
