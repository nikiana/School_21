/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:12:20 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 14:22:16 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void		sort_array(int *arr, int len)
{
	int i;
	int tmp;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void		get_indexes(t_list *a, int len)
{
	int		*arr;
	int		i;
	t_list	*ptr;

	arr = (int*)malloc(sizeof(int) * len);
	ptr = a;
	i = 0;
	while (ptr)
	{
		arr[i++] = ptr->content;
		ptr = ptr->next;
	}
	sort_array(arr, len);
	while (a)
	{
		i = 0;
		while (a->content != arr[i])
			i++;
		a->index = i;
		a = a->next;
	}
	free(arr);
}

void			sort_small(t_list **a, t_list **b, int sz, t_flags *flag)
{
	if ((*a)->content > (*a)->next->content)
	{
		if (sz == 3 && (*a)->content > (*a)->next->next->content &&
		(*a)->next->content < (*a)->next->next->content)
			p_ra(a, *b, flag);
		else
		{
			p_sa(*a, *b, flag);
			if (!is_sorted(*a))
				p_rra(a, *b, flag);
		}
	}
	else
	{
		p_rra(a, *b, flag);
		if (!is_sorted(*a))
			p_sa(*a, *b, flag);
	}
}

void			sort_medium(t_list **a, t_list **b, int sz, t_flags *flag)
{
	int	i;

	while (!is_sorted(*a))
	{
		i = find_min(*a, 0);
		if (i > sz / 2)
			while (i < sz && ++i)
				p_rra(a, *b, flag);
		else
			while (i--)
				p_ra(a, *b, flag);
		is_sorted(*a) ? 1 : p_pb(a, b, flag);
		sz--;
	}
	while (*b)
		p_pa(b, a, flag);
}

void			sort_large(t_list **a, t_list **b, int sz, t_flags *flag)
{
	int *delim;

	delim = (int*)malloc(sizeof(int) * 3);
	get_indexes(*a, sz);
	if (sz <= 200)
	{
		delim[0] = sz / 10;
		delim[1] = 4;
		delim[2] = 6;
	}
	if (sz > 200)
	{
		delim[0] = sz / 19;
		delim[1] = 9;
		delim[2] = 11;
	}
	parse_a_list(a, b, delim, flag);
	from_b_to_a(a, b, flag);
}
