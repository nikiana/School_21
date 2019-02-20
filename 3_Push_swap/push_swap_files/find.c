/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:10:18 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 14:16:42 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		find_max(t_list *a, int *val)
{
	int i;
	int max;
	int res;

	res = 0;
	i = 0;
	max = -2147483648;
	while (a)
	{
		if (a->content > max)
		{
			max = a->content;
			res = i;
			if (val)
				*val = max;
		}
		a = a->next;
		i++;
	}
	return (res);
}

int		find_min(t_list *a, int *val)
{
	int i;
	int min;
	int res;

	res = 0;
	i = 0;
	min = 2147483647;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			res = i;
			if (val)
				*val = min;
		}
		a = a->next;
		i++;
	}
	return (res);
}

int		find_min_ind(t_list *a)
{
	int res;

	res = 2147483647;
	while (a)
	{
		if (a->index < res)
			res = a->index;
		a = a->next;
	}
	return (res);
}

int		find_max_ind(t_list *a)
{
	int res;

	res = 0;
	while (a)
	{
		if (a->index > res)
			res = a->index;
		a = a->next;
	}
	return (res);
}

int		find_place(int ind, t_list *a)
{
	int i;
	int save_i;
	int max_ind;

	i = 0;
	save_i = 0;
	max_ind = find_max_ind(a);
	if (ind > max_ind && a)
	{
		while (a->index != max_ind && ++i)
			a = a->next;
		return (i + 1);
	}
	max_ind = 2147483647;
	while (a)
	{
		if (ind < a->index)
			if (a->index < max_ind)
			{
				max_ind = a->index;
				save_i = i;
			}
		a = (i++) ? a->next : a->next;
	}
	return (save_i);
}
