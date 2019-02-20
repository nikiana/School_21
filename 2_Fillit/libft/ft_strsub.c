/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:17:03 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/23 16:25:45 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s)
	{
		if (!(sub = ft_strnew(len)))
			return (NULL);
		ft_strncpy(sub, s + start, len);
		return (sub);
	}
	return (NULL);
}
