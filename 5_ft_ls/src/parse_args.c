/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:00:42 by kcarrot           #+#    #+#             */
/*   Updated: 2019/03/01 12:49:48 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	links(struct stat buf, char *name, unsigned long fl)
{
	char	*str;
	char	b[100];
	int		link;

	if (fl >> ('z' - 'l') & (unsigned long)1)
		return (0);
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		link = readlink(name, b, 100);
		str = ft_strnew(link + 1);
		str = ft_strncpy(str, b, link);
		stat(str, &buf);
		if (buf.st_mode & S_IFDIR)
		{
			free(str);
			return (1);
		}
	}
	return (0);
}

static void	get_info(char *av, t_file **files, t_file **dirs, unsigned long fl)
{
	struct stat	buf;
	t_file		*new;
	static int	i;
	static int	j;

	if (lstat(av, &buf) == -1)
		ft_printf("ls: %s: No such file or directory\n", av);
	else
	{
		new = (t_file *)malloc(sizeof(t_file));
		new->name = ft_strdup(av);
		new->path = ft_strdup(av);
		new->name_len = ft_strlen(av);
		new->mode = buf.st_mode;
		new->nlink = buf.st_nlink;
		new->size = buf.st_size;
		new->time = buf.st_mtimespec;
		new->uid = buf.st_uid;
		new->gid = buf.st_gid;
		new->dev = buf.st_rdev;
		if ((buf.st_mode & S_IFMT) == S_IFDIR || links(buf, new->name, fl))
			dirs[i++] = new;
		else
			files[j++] = new;
	}
}

static void	cur_dir(t_file **dirs)
{
	struct stat	buf;

	dirs[1] = 0;
	dirs[0] = (t_file*)malloc(sizeof(t_file));
	lstat(".", &buf);
	dirs[0]->name = ft_strdup(".");
	dirs[0]->path = ft_strdup(".");
	dirs[0]->name_len = 0;
	dirs[0]->mode = buf.st_mode;
	dirs[0]->nlink = buf.st_nlink;
	dirs[0]->size = buf.st_size;
	dirs[0]->time = buf.st_mtimespec;
	dirs[0]->uid = buf.st_uid;
	dirs[0]->gid = buf.st_gid;
}

t_file		**parse_args(int ac, char **av, t_file **dirs, unsigned long fl)
{
	int		i;
	t_file	**files;

	files = (t_file**)malloc(sizeof(t_file*) * (ac + 1));
	i = 0;
	while (i <= ac)
	{
		dirs[i] = 0;
		files[i] = 0;
		i++;
	}
	g_arg = (ac > 1) ? 1 : 0;
	if (!ac)
		cur_dir(dirs);
	while (ac--)
	{
		get_info(*av, files, dirs, fl);
		av++;
	}
	return (files);
}
