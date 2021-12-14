/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:10:53 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/14 23:10:55 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ss1;
	int		ss2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	str = (char *)ft_calloc((ss1 + ss2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, ss1 + 1);
	ft_strlcat(&str[ss1], s2, ss2 + 1);
	return (str);
}
