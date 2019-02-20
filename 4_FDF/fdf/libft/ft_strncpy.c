/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:15:49 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/24 20:15:38 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p;
	size_t	l;

	l = 0;
	p = dst;
	while (*src && len)
	{
		*dst++ = *src++;
		len--;
	}
	while (len-- != 0)
		*dst++ = '\0';
	return (p);
}
