/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:32:49 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 14:36:52 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int		there_are_idx(t_list *a, int delim, int min, int max)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->index >= min * delim && a->index < max * delim)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void			parse_a_last(t_list **a, t_list **b, int delim, t_flags *flag)
{
	while (*a)
	{
		p_pb(a, b, flag);
		if ((*b)->index >= 0 && (*b)->index < delim)
			p_rb(*a, b, flag);
	}
}

static void		parse_help(t_list **a, t_list **b, int *delim, t_flags *flag)
{
	if (*b && (*b)->index >= delim[1] * delim[0] &&
	(*b)->index < (delim[1] + 1) * delim[0] &&
	there_are_idx(*b, delim[0], delim[1] + 1, delim[2]) != -1)
		p_rr(a, b, flag);
	else
		p_ra(a, *b, flag);
}

static void		parse_help2(t_list **a, t_list **b, int i, t_flags *flag)
{
	if (i && i < ft_list_size(*a) / 2)
		p_rr(a, b, flag);
	else
		p_rb(*a, b, flag);
}

void			parse_a_list(t_list **a, t_list **b, int *delim, t_flags *flag)
{
	int i;

	if (delim[1] > 0)
	{
		while ((i = there_are_idx(*a, delim[0], delim[1], delim[2])) != -1)
		{
			if (*b && (*b)->index >= delim[1] * delim[0] &&
			(*b)->index < (delim[1] + 1) * delim[0] &&
			there_are_idx(*b, delim[0], delim[1] + 1, delim[2]) != -1)
				parse_help2(a, b, i, flag);
			else if (i && i < ft_list_size(*a) / 2)
				parse_help(a, b, delim, flag);
			else if (i == 0)
				p_pb(a, b, flag);
			else if (i >= ft_list_size(*a) / 2)
				p_rra(a, *b, flag);
		}
		delim[2] += (delim[1]--) ? 1 : 1;
		parse_a_list(a, b, delim, flag);
	}
	parse_a_last(a, b, delim[0], flag);
}
