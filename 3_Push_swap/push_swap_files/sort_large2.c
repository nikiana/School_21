/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:52:27 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 14:23:40 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void		rotate_a(t_list **a, t_list **b, t_flags *flag)
{
	int i;
	int a_sz;

	a_sz = ft_list_size(*a);
	i = find_min(*a, 0);
	if (i > a_sz / 2)
		while (i++ < a_sz && (!*b || (*a)->index > (*b)->index))
			p_rra(a, *b, flag);
	else
		while (i--)
			p_ra(a, *b, flag);
}

void			from_b_to_a(t_list **a, t_list **b, t_flags *flag)
{
	int sz;
	int ind;
	int min;

	while (*b)
	{
		sz = ft_list_size(*a);
		min = find_min_ind(*a);
		ind = find_place((*b)->index, *a);
		if (ind > sz / 2)
			while (ind++ < sz)
				p_rra(a, *b, flag);
		else
			while (ind--)
				p_ra(a, *b, flag);
		p_pa(b, a, flag);
	}
	rotate_a(a, b, flag);
}
