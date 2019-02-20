/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:55:01 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/30 14:00:02 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_atoi(const char *str, int *sign)
{
	if (*sign == 1)
		if (ft_strncmp(str, "9223372036854775807", 19) > 0)
			return (-1);
	if (*sign == -1)
		if (ft_strncmp(str, "9223372036854775808", 19) > 0)
			return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int res;
	int sign;
	int i;

	sign = 1;
	res = 0;
	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (str[i] >= '0' && str[i] <= '9' && i < 19)
		res = res * 10 + (str[i++] - '0');
	if (i == 19 && check_atoi(str, &sign) == -1)
		return (-1);
	if (i == 19 && check_atoi(str, &sign) == 0)
		return (0);
	return (res * sign);
}
