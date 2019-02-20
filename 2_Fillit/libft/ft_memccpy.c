/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/26 11:38:01 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n--)
		if ((*cdst++ = *csrc++) == (unsigned char)c)
			return (cdst);
	return (NULL);
}
