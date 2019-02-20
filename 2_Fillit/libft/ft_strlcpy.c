/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:14:09 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/28 16:33:25 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	n = size;
	i = 0;
	if (!src || !dst)
		return (0);
	while (--n != 0)
	{
		if ((dst[i] = src[i]) == '\0')
			break ;
		i++;
	}
	if (n == 0)
	{
		if (size != 0)
			dst[i] = '\0';
	}
	return (ft_strlen(src));
}
