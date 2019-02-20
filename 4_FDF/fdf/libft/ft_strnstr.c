/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:48:25 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/28 11:37:46 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!(*needle))
		return ((char*)haystack);
	if (!(*haystack))
		return (0);
	while (len && *haystack)
	{
		while (*needle != *haystack && *haystack && --len)
			haystack++;
		if (ft_strlen(needle) > len)
			return (0);
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char*)haystack);
		if (*haystack)
			haystack++;
	}
	return (0);
}
