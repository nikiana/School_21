/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:39:58 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:21:03 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		swap(t_file **fls, int one, int two)
{
	t_file *tmp;

	tmp = fls[one];
	fls[one] = fls[two];
	fls[two] = tmp;
}

static int	is_sorted(t_file **fls, int st, int end)
{
	while (fls[st] && fls[st + 1] && st < end)
	{
		if (fls[st]->time.tv_sec < fls[st + 1]->time.tv_sec)
			return (0);
		st++;
	}
	return (1);
}

static void	quicksort(t_file **fls, int st, int end)
{
	int			left;
	int			right;
	long int	middle;

	if (st < end && !(is_sorted(fls, st, end)))
	{
		left = st;
		right = end;
		middle = (fls[(left + right) / 2])->time.tv_sec;
		while (left < right)
		{
			while (fls[left]->time.tv_sec > middle && left < right)
				left++;
			while (fls[right]->time.tv_sec < middle && left < right)
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
		if (fls[st]->time.tv_sec == fls[st - 1]->time.tv_sec)
		{
			if (ft_strcmp(fls[st - 1]->name, fls[st]->name) > 0)
			{
				swap(fls, st, st - 1);
				while (st > 0 &&
					fls[st]->time.tv_sec == fls[st - 1]->time.tv_sec)
					st--;
			}
		}
		st++;
	}
}

void		sort_time(t_file **files, unsigned long flags)
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
