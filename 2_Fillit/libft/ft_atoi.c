/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:14:06 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/27 16:53:54 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	long	sig;
	int		i;

	sig = 1;
	res = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (res > 922337203685477580 || (res == 922337203685477580 &&
			str[i] - '0' > 7))
			return ((sig == 1) ? -1 : 0);
		res = res * 10 + str[i++] - '0';
	}
	return (sig * res);
}
