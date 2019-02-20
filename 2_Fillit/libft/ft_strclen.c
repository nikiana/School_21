/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:22:17 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/12/03 13:00:38 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char *str, char c)
{
	size_t len;

	len = 0;
	while (str[len])
	{
		if (str[len] == c || str[len] == '\0')
			return (len);
		len++;
	}
	return (len);
}
