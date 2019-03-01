/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:58:52 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 21:35:49 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		sort_args(t_file **fls, unsigned long flag)
{
	int		i;

	i = 0;
	if (!(flag >> ('z' - 'r') & (unsigned long)1))
		while (fls[i + 1])
		{
			if (ft_strcmp(fls[i]->name, fls[i + 1]->name) > 0)
			{
				swap(fls, i, i + 1);
				i = -1;
			}
			i++;
		}
	else
		while (fls[i + 1])
		{
			if (ft_strcmp(fls[i]->name, fls[i + 1]->name) < 0)
			{
				swap(fls, i, i + 1);
				i = -1;
			}
			i++;
		}
}

int			main_continue(unsigned long flags, t_file **files, t_file **dirs)
{
	if (*files)
	{
		if (!(flags >> ('z' - 'S') & (unsigned long)1) &&
			!(flags >> ('z' - 't') & (unsigned long)1))
			sort_args(files, flags);
		else
			sort_files(flags, files);
		show_files(flags, files, 0, 0);
		*dirs ? write(1, "\n", 1) : 0;
	}
	if (*dirs)
	{
		if (!(flags >> ('z' - 'S') & (unsigned long)1) &&
			!(flags >> ('z' - 't') & (unsigned long)1))
			sort_args(dirs, flags);
		else
			sort_files(flags, dirs);
		show_dirs(dirs, flags);
	}
	free_file(files);
	free_file(dirs);
	return (0);
}

int			main(int ac, char **av)
{
	unsigned long	flags;
	t_file			**files;
	t_file			**dirs;

	flags = 0;
	av++;
	while (--ac && **av == '-' && *(*av + 1))
	{
		if (ft_strcmp(*av, "--"))
			if (check_flags(*av, &flags))
				return (1);
		av++;
	}
	if (flags & (unsigned long)1)
		return (print_usage());
	dirs = ac ? (t_file**)malloc(sizeof(t_file*) * (ac + 1)) :
		(t_file**)malloc(sizeof(t_file*) * 2);
	files = parse_args(ac, av, dirs, flags);
	main_continue(flags, files, dirs);
	return (0);
}
