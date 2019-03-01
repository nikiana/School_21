/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:26:43 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/27 20:26:28 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		**free_arr(char ***arr)
{
	int	i;

	i = 0;
	while (*arr[i++])
		free(*arr[i]);
	free(arr);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;

	i = 0;
	if (!s || !(res = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		k = 0;
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(res[i] = (char*)malloc(sizeof(char) * len(s, c) + 1)))
				return (free_arr(&res));
			while (*s && *s != c)
				res[i][k++] = (char)*(s++);
			res[i++][k] = '\0';
		}
	}
	res[i] = 0;
	return (res);
}
