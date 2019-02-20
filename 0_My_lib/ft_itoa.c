/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:23:01 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/27 20:26:49 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(int n, unsigned int *n2)
{
	int				i;
	unsigned int	k;

	i = 0;
	k = n;
	if (n <= 0)
	{
		i = 1;
		*n2 = -n;
		k = -n;
	}
	else
		*n2 = n;
	while (k > 0)
	{
		i++;
		k = k / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				l;
	unsigned int	n2;
	char			*new;

	l = check(n, &n2);
	if (!(new = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	new[l] = '\0';
	l--;
	if (n < 0)
		new[0] = '-';
	if (n == 0)
		new[0] = '0';
	while (n2 > 0)
	{
		new[l--] = n2 % 10 + '0';
		n2 = n2 / 10;
	}
	return (new);
}
