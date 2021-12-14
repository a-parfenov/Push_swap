/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:10:27 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/14 23:10:32 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count_wrd;
	int	flag;

	flag = 0;
	count_wrd = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else
		{
			if (flag == 0)
				++count_wrd;
			flag = 1;
		}
		++i;
	}
	return (count_wrd);
}

static int	ft_len_word(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		++len;
	return (len);
}

static char	**ft_main(char const *s, int index_s, char c, char **array)
{
	int		i;
	int		len_word;

	i = 0;
	while (s[index_s])
	{
		len_word = ft_len_word(s + index_s, c) + 1;
		array[i] = (char *) malloc(len_word * sizeof(char));
		if (array[i] == (0))
		{
			while (*(array + i))
				free(array[i--]);
			free(array);
			return (0);
		}
		ft_memset(array[i], '\0', len_word);
		ft_strlcat(array[i], s + index_s, (size_t)len_word);
		index_s += len_word - 1;
		++i;
		while (s[index_s] && s[index_s] == c && c != '\0')
			++index_s;
	}
	array[i] = (0);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		index_s;
	char	**result;

	if (s == NULL)
		return (NULL);
	array = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	index_s = 0;
	while (s[index_s] && s[index_s] == c && c != '\0')
		++index_s;
	result = (ft_main(s, index_s, c, array));
	return (result);
}
