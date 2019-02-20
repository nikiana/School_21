/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:49:46 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/25 13:20:20 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s || !(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (len != 0)
	{
		new[i++] = s[start++];
		len--;
	}
	new[i] = '\0';
	return (new);
}
