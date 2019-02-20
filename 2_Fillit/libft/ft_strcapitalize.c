/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:16:41 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/27 17:27:09 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && !ft_isalnum(str[i - 1]))
			ft_toupper(str[i]);
		else if ((str[i] >= 'A' && str[i] <= 'Z') && ft_isalnum(str[i - 1]))
			ft_tolower(str[i]);
		i++;
	}
	return (str);
}
