/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 12:51:46 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:26:15 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_file	*get_info(struct dirent *next, char *str,
					unsigned int *total, unsigned long flags)
{
	struct stat		buf;
	t_file			*new;

	new = (t_file *)malloc(sizeof(t_file));
	new->path = ft_strjoin_3(str, "/", next->d_name);
	new->name = ft_strdup(next->d_name);
	lstat(new->path, &buf);
	new->name_len = next->d_namlen;
	new->size = buf.st_size;
	new->mode = buf.st_mode;
	new->time = buf.st_mtimespec;
	*total += buf.st_blocks;
	if (flags & (unsigned long)1 << ('z' - 'l'))
	{
		new->nlink = buf.st_nlink;
		new->uid = buf.st_uid;
		new->gid = buf.st_gid;
		new->dev = buf.st_rdev;
	}
	return (new);
}

static t_file	**all_inside_dir(char *str, unsigned long flags, unsigned int i)
{
	DIR				*dir;
	struct dirent	*next;
	t_file			**new;
	unsigned int	total;

	if (!(dir = opendir(str)))
	{
		ft_printf("ls: %s: Permission denied\n", str);
		new = (t_file **)malloc(sizeof(t_file));
		new[0] = 0;
		return (new);
	}
	while ((next = readdir(dir)))
		i++;
	dir = closedir(dir) ? opendir(str) : opendir(str);
	new = (t_file **)malloc(sizeof(t_file *) * (i + 1));
	i = 0;
	total = 0;
	while ((next = readdir(dir)) != NULL)
		if (*(next->d_name) != '.' || (flags >> ('z' - 'a') & (unsigned long)1))
			new[i++] = get_info(next, str, &total, flags);
	if ((flags >> ('z' - 'l') & (unsigned long)1) && i > 0)
		ft_printf("total %d\n", total);
	new[i] = 0;
	return (closedir(dir)) ? new : new;
}

static void		recursion(t_file **new, unsigned long flags)
{
	int		i;
	t_file	**next;

	g_arg = 1;
	i = 0;
	while (new[i])
	{
		if ((new[i]->mode & S_IFMT) == S_IFDIR &&
			(new[i]->mode & S_IFMT) != S_IFBLK)
			if (!ft_strequ(new[i]->name, ".") &&
				!ft_strequ(new[i]->name, "..") &&
					(*(new[i]->name) != '.' || (flags >> ('z' - 'a') & 1)))
			{
				next = (t_file **)malloc(sizeof(t_file*) * 2);
				next[0] = new[i];
				next[1] = 0;
				write(1, "\n", 1);
				show_dirs(next, flags);
				free(next);
			}
		i++;
	}
	free_file(new);
}

int				show_dirs(t_file **files, unsigned long flags)
{
	t_file		**new;

	while (*files)
	{
		g_arg ? ft_printf("%s:\n", (*files)->path) : 0;
		if (!((*files)->mode & S_IRUSR))
		{
			ft_printf("ls: %s: Permission denied\n", (*files)->name);
			files++;
			continue;
		}
		if (!ft_strcmp(files[0]->name, "/dev") && show_dev(&files, flags, 0))
			continue ;
		new = all_inside_dir((*files)->path, flags, 0);
		sort_files(flags, new);
		show_files(flags, new, 0, 0);
		if (flags & (unsigned long)1 << ('z' - 'R'))
			recursion(new, flags);
		else
			free_file(new);
		if (*(files + 1))
			write(1, "\n", 1);
		files++;
	}
	return (0);
}
