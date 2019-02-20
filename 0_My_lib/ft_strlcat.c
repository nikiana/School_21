/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:23:57 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/27 14:41:01 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int s;
	int d;

	i = size + 1;
	s = ft_strlen(src);
	d = ft_strlen(dst);
	while (--i > 0 && *dst)
		dst++;
	if (i == 0)
		return (size + s);
	while (i > 1 && *src)
	{
		*dst++ = *src++;
		i--;
	}
	if (i-- > 0)
		*dst = '\0';
	return (d + s);
}
