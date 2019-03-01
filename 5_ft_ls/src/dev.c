/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:16:16 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 20:55:52 by kcarrot          ###   ########.fr       */
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
	new->time = buf.st_mtimespec;
	new->mode = buf.st_mode;
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

static void		sort_dev(t_file **new, unsigned long flags)
{
	if (flags >> ('z' - 'f') & (unsigned long)1)
		return ;
	if (flags >> ('z' - 'S') & (unsigned long)1)
	{
		sort_args(new, flags);
		sort_size(new, flags);
	}
	else if (flags >> ('z' - 't') & (unsigned long)1)
	{
		sort_args(new, flags);
		sort_time(new, flags);
	}
	else
		sort_args(new, flags);
}

int				show_dev(t_file ***fl, unsigned long flags, int i)
{
	DIR				*dir;
	struct dirent	*next;
	t_file			**new;
	unsigned int	total;

	dir = opendir("/dev");
	while ((next = readdir(dir)))
		i++;
	dir = closedir(dir) ? opendir("/dev") : opendir("/dev");
	new = (t_file **)malloc(sizeof(t_file *) * (i + 1));
	i = 0;
	total = 0;
	while ((next = readdir(dir)) != NULL)
		if (*(next->d_name) != '.' || (flags >> ('z' - 'a') & (unsigned long)1))
			new[i++] = get_info(next, "/dev", &total, flags);
	if ((flags >> ('z' - 'l') & (unsigned long)1) && i > 0)
		ft_printf("total %d\n", total);
	new[i] = 0;
	sort_dev(new, flags);
	show_files(flags, new, 0, 1);
	free_file(new);
	(*fl)++;
	return (1);
}
