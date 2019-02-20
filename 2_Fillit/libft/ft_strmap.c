/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:17:13 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/29 15:47:48 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(res = ft_strdup(s)))
		return (NULL);
	while (res[i])
	{
		res[i] = (*f)(res[i]);
		i++;
	}
	return (res);
}
