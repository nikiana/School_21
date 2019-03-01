/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:52:43 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:20:38 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	is_big(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			return (1);
		str++;
	}
	return (0);
}

void		sort_abc(t_file **files, unsigned long flags, int i, int j)
{
	while (files[i])
	{
		if (is_big(files[i]->name))
		{
			j = i;
			while (j > 0 && ft_strcmp(files[j]->name, files[j - 1]->name) < 0)
			{
				swap(files, j, j - 1);
				j--;
			}
		}
		i++;
	}
	j = 0;
	if (flags >> ('z' - 'r') & (unsigned long)1)
	{
		while (j < --i)
		{
			swap(files, i, j);
			j++;
		}
	}
}

void		sort_files(unsigned long flags, t_file **files)
{
	if (!(files[0]))
		return ;
	if (flags >> ('z' - 'f') & (unsigned long)1)
		return ;
	if (flags >> ('z' - 'S') & (unsigned long)1)
		sort_size(files, flags);
	else if (flags >> ('z' - 't') & (unsigned long)1)
		sort_time(files, flags);
	else
		sort_abc(files, flags, 0, 0);
}
