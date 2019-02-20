/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:51:52 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/22 18:05:11 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (i < n)
	{
		uc1 = *(unsigned char *)(s1 + i);
		uc2 = *(unsigned char *)(s2 + i);
		if (uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	return (0);
}
