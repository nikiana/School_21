/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:14:08 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:54:19 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		count(t_file **fls, int *sz, int *ln)
{
	int i;
	int sz2;
	int ln2;

	sz2 = 0;
	ln2 = 0;
	i = 0;
	while (fls[i])
	{
		if (fls[i]->size > sz2)
			sz2 = fls[i]->size;
		if (fls[i]->nlink > ln2)
			ln2 = fls[i]->nlink;
		i++;
	}
	*sz = 1;
	while ((sz2 /= 10) > 0)
		(*sz)++;
	*ln = 1;
	while ((ln2 /= 10) > 0)
		(*ln)++;
}

static void		help(t_file **files, int i, int row, int max_len)
{
	int		j;
	char	*help;

	j = i;
	while (files[j])
	{
		if (!((j - i) % row))
		{
			if ((files[j]->mode & S_IFMT) == S_IFDIR)
			{
				help = ft_strjoin(files[j]->name, "/");
				ft_printf("%-*s ", max_len, help);
				free(help);
			}
			else
				ft_printf("%-*s ", max_len, (files[j])->name);
		}
		j++;
	}
}

static void		print_colmn(t_file **files, struct winsize w)
{
	int		max_len;
	int		col;
	int		row;
	int		i;
	int		j;

	i = 0;
	max_len = find_max(files, &row);
	col = (w.ws_col / max_len);
	row = (row % col) ? (row / col + 1) : row / col;
	while (files[i] && i < row)
	{
		j = i;
		while (files[j])
		{
			if (!((j - i) % row))
				ft_printf("%-*s", max_len, (files[j])->name);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

static void		print_colmnp(t_file **files, struct winsize w)
{
	int		max_len;
	int		col;
	int		row;
	int		i;

	i = 0;
	max_len = find_max(files, &row);
	col = (w.ws_col / max_len);
	row = (row % col) ? (row / col + 1) : row / col;
	while (files[i] && i < row)
	{
		help(files, i, row, max_len);
		i++;
		write(1, "\n", 1);
	}
}

void			show_files(unsigned long flags, t_file **files, int i, int si)
{
	struct winsize	w;
	int				sz;
	int				ln;

	flags |= si ? ((unsigned long)1 << 62) : flags;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (flags >> 14 & (unsigned long)1)
	{
		count(files, &sz, &ln);
		count_g_len(files);
		while (files[i])
			long_format(files[i++], flags, sz, ln);
	}
	else if (flags >> 63 & (unsigned long)1)
		while (files[i])
		{
			if (*(files[i]->name) == '.' && !(flags >> ('z' - 'a') & 1))
				i++;
			else
				ft_printf("%s%c\n", (files[i++])->name, ((flags >> 10) & 1 &&
				(files[i]->mode & S_IFMT) == S_IFDIR) ? '/' : 0);
		}
	else
		(flags >> ('z' - 'p') & (unsigned long)1) ?
		print_colmnp(files, w) : print_colmn(files, w);
}
