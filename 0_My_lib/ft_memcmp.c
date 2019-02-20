/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:50:57 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/21 16:53:42 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s;
	const unsigned char *ss;

	s = (const unsigned char*)s1;
	ss = (const unsigned char*)s2;
	while (n--)
	{
		if (*s != *ss)
			return (*s - *ss);
		s++;
		ss++;
	}
	return (0);
}
