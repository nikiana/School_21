/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:34:50 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/23 21:13:14 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (haystack[i] == needle[i] && haystack[i] == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i] && i <= len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] &&
			haystack[i + j] == needle[j])
			j++;
		if (!needle[j] && i + j <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
