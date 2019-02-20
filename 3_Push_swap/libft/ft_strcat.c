/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:42:26 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/21 18:03:56 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *p;

	p = s1;
	while (*p)
		p++;
	while (*s2)
	{
		*p = *s2;
		s2++;
		p++;
	}
	*p = '\0';
	return (s1);
}