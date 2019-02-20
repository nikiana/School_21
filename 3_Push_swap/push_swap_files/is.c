/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:00:03 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/22 18:30:27 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int		is_rev_sorted(t_list *b)
{
	while (b && b->next)
	{
		if (b->content < b->next->content)
			return (0);
		b = b->next;
	}
	return (1);
}

int		is_valid(t_list *a, long int i)
{
	t_list *tmp;

	if (i < -2147483648 || i > 2147483647)
		return (0);
	tmp = a;
	while (tmp)
	{
		if (i == tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
