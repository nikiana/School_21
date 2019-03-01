/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:11:34 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:20:27 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	is_sorted(t_file **fls, int st, int end)
{
	while (fls[st] && fls[st + 1] && st < end)
	{
		if (fls[st]->size < fls[st + 1]->size)
			return (0);
		st++;
	}
	return (1);
}

static void	quicksort(t_file **fls, int st, int end)
{
	int left;
	int right;
	int middle;

	if (st < end && !(is_sorted(fls, st, end)))
	{
		left = st;
		right = end;
		middle = (fls[(left + right) / 2])->size;
		while (left < right)
		{
			while (fls[left]->size > middle && left < right)
				left++;
			while (fls[right]->size < middle && left < right)
				right--;
			if (left < right)
			{
				swap(fls, left, right);
				left++;
				right--;
			}
		}
		quicksort(fls, st, right);
		quicksort(fls, left, end);
	}
}

static void	check_abc(t_file **fls)
{
	int st;

	st = 1;
	while (fls[st])
	{
		if (fls[st]->size == fls[st - 1]->size)
		{
			if (ft_strcmp(fls[st - 1]->name, fls[st]->name) > 0)
			{
				swap(fls, st, st - 1);
				while (st > 0 && fls[st]->size == fls[st - 1]->size)
					st--;
			}
		}
		st++;
	}
}

void		sort_size(t_file **files, unsigned long flags)
{
	int		end;
	int		i;

	end = 0;
	while (files[end + 1])
		end++;
	quicksort(files, 0, end);
	check_abc(files);
	if (flags >> ('z' - 'r') & (unsigned long)1)
	{
		i = 0;
		while (i < end)
		{
			swap(files, i, end);
			i++;
			end--;
		}
	}
}
