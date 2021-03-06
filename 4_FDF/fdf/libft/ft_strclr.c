/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:21:35 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/25 14:41:12 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s && *s)
	{
		while (*(s + 1))
		{
			*s = '\0';
			s++;
		}
		*s = '\0';
	}
}
