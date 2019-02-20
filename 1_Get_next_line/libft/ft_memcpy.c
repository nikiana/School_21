/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:47:00 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/29 15:49:29 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*p;
	char		*d;

	if (dst == src)
		return (dst);
	p = src;
	d = dst;
	while (n--)
		*d++ = *p++;
	return (dst);
}
