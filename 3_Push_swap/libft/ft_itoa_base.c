/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:51:26 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/26 12:50:52 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*almost(unsigned long int value, int base, int *l)
{
	unsigned long int	n;
	int					i;
	char				*res;

	n = value;
	i = 0;
	while (n > 0)
	{
		n = n / base;
		(*l)++;
	}
	res = ft_strnew(*l);
	while (value > 0)
	{
		n = value % base;
		if (n <= 9)
			res[i] = n + '0';
		if (n >= 10 && n <= 15)
			res[i] = n + 87;
		value = value / base;
		i++;
	}
	return (res);
}

char		*ft_itoa_base(unsigned long int value, int base)
{
	char	*r;
	char	*res;
	int		l;
	int		i;

	i = 0;
	l = 0;
	value *= (value > 0) ? 1 : -1;
	if (value == 0)
	{
		res = ft_strnew(1);
		res[0] = '0';
		return (res);
	}
	r = almost(value, base, &l);
	res = ft_strnew(l);
	while (l > 0)
	{
		res[i] = r[l - 1];
		i++;
		l--;
	}
	free(r);
	return (res);
}
