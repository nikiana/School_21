/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:30:05 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/23 16:15:55 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	i;
	int				sig;
	long			k;

	k = (long)n;
	i = 0;
	if (!(s = ft_strnew(11)))
		return (NULL);
	if ((sig = k) < 0)
		k = -k;
	if (k == 0)
		s[i] = '0';
	while (k > 0)
	{
		s[i] = k % 10 + '0';
		k /= 10;
		i++;
	}
	if (sig < 0)
		s[i++] = '-';
	return (ft_strrev(s));
}
