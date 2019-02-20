/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:05:47 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/11 17:13:22 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*strnew(int n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = ft_strnew(n * (n + 1));
	ft_memset(res, '.', (n * (n + 1)));
	while (res[i])
	{
		if ((i + 1) % (n + 1) == 0)
			res[i] = '\n';
		i++;
	}
	return (res);
}

int		ft_sqrt(int nb)
{
	int n;

	n = 2;
	while ((n * n) != nb)
		n++;
	return (n);
}

int		smallest_sqr(t_lst *head)
{
	size_t i;

	i = (lst_size(head) * 4);
	while (i != 4 && i != 9 && i != 16 && i != 25 && i != 36 &&
		i != 49 && i != 64 && i != 81 && i != 100 && i != 121)
		i++;
	return (ft_sqrt(i));
}
