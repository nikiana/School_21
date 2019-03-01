/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:41 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/24 13:00:35 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_3(char const *s1, char const *s2, char const *s3)
{
	char	*new;
	int		i;

	if (!(new = (char*)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		new[i++] = *s2;
		s2++;
	}
	while (s3 && *s3)
	{
		new[i++] = *s3;
		s3++;
	}
	new[i] = '\0';
	return (new);
}
