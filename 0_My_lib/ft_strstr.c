/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:37:42 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/21 21:46:29 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!(*haystack) && !(*needle))
		return ((char*)haystack);
	if (!(*haystack))
		return (0);
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack)
	{
		while (*needle != *haystack && *haystack)
			haystack++;
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char*)haystack);
		if (*haystack)
			haystack++;
	}
	return (0);
}
