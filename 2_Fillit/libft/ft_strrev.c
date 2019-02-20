/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:50:08 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/29 16:50:23 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t		i;
	size_t		j;
	char		*res;

	res = ft_strnew(ft_strlen(s));
	i = 0;
	j = ft_strlen(s) - 1;
	while (i < ft_strlen(s))
	{
		res[i] = s[j];
		i++;
		j--;
	}
	return (res);
}
