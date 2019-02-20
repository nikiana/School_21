/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:52:00 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/29 15:39:41 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	end;

	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (ft_iswhitespace(s[start]))
			start++;
		if (start == end)
			return (ft_strnew(1));
		while (ft_iswhitespace(s[end - 1]))
			end--;
		if (!(new = ft_strnew(end - start)))
			return (NULL);
		new = ft_strncpy(new, s + start, end - start);
		return (new);
	}
	return (NULL);
}
