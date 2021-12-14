/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:11:56 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/14 23:11:58 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_main(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	len_str;
	int				temp;
	int				i;

	temp = len;
	if (!s || start < 0)
		return (NULL);
	len_str = ft_strlen(s);
	if (len_str <= len)
		temp = len_str;
	if (len_str < start)
		return (ft_main());
	str = (char *)malloc(temp + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < temp)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
