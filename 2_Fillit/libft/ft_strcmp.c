/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:45:29 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/23 21:05:46 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	uc1 = s1[i];
	uc2 = s2[i];
	while (s1[i] && (uc1 == uc2))
	{
		i++;
		uc1 = s1[i];
		uc2 = s2[i];
	}
	return (uc1 - uc2);
}
