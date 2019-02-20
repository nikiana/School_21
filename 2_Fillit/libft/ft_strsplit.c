/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:39:58 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/27 19:33:29 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wordcount(char const *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			word++;
		i++;
	}
	return (word);
}

static	char	**ft_free2d(char **words)
{
	size_t i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		words[i] = NULL;
		i++;
	}
	ft_memdel((void **)words);
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	buf;
	int		words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	i = 0;
	j = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (words-- > 0)
	{
		while (s[i] && s[i] == c)
			i++;
		buf = i;
		while (s[i] && s[i] != c)
			i++;
		if (!(split[j++] = ft_strsub(s, buf, i - buf)))
			return (ft_free2d(split));
	}
	split[j] = NULL;
	return (split);
}
