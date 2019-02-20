/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:17:07 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/11 17:17:12 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		check_and_place(char *res, t_lst *map, int n)
{
	if ((res)[IND0] != '.' || (res)[IND1] != '.' || (res)[IND2] != '.' ||
		(res)[IND3] != '.')
		return (0);
	(res)[IND0] = map->ltr;
	(res)[IND1] = map->ltr;
	(res)[IND2] = map->ltr;
	(res)[IND3] = map->ltr;
	return (1);
}

static void		dot_place(char *res, t_lst *map, int n)
{
	(res)[IND0] = '.';
	(res)[IND1] = '.';
	(res)[IND2] = '.';
	(res)[IND3] = '.';
}

static int		solution(t_lst *head, char **res, int n)
{
	size_t i;

	i = 0;
	if (!head)
		return (1);
	while ((*res)[i])
	{
		if (check_and_place((*res + i), head, n))
		{
			if (solution(head->next, res, n))
				return (1);
			dot_place((*res + i), head, n);
		}
		i++;
	}
	return (0);
}

void			ft_solve(t_lst *head, char **res)
{
	size_t n;

	n = smallest_sqr(head);
	while (1)
	{
		*res = strnew(n);
		if (solution(head, res, n))
		{
			ft_putstr(*res);
			free(*res);
			break ;
		}
		free(*res);
		n++;
	}
}
