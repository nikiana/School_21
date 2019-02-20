/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:36:15 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/25 14:06:44 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		*d;
	unsigned char		cc;

	p = src;
	d = dst;
	cc = c;
	while (n--)
	{
		*d = *p;
		if (*p == cc)
			return (++d);
		d++;
		p++;
	}
	return (NULL);
}
