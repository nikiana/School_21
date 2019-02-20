/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:53:37 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/29 16:11:05 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		len;
	char		*new;

	len = ft_strlen(src);
	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_strcpy(new, src);
	return (new);
}
