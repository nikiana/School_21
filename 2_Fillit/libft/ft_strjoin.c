/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:37:16 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/23 17:49:44 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (s1 && s2)
	{
		if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		res = ft_strcpy(res, s1);
		res = ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
