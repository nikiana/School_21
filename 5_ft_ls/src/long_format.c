/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:53:59 by kcarrot           #+#    #+#             */
/*   Updated: 2019/03/01 12:49:36 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		print_type(int mode)
{
	if ((mode & S_IFMT) == S_IFDIR)
		write(1, "d", 1);
	else if ((mode & S_IFMT) == S_IFREG)
		write(1, "-", 1);
	else if ((mode & S_IFMT) == S_IFIFO)
		write(1, "p", 1);
	else if ((mode & S_IFMT) == S_IFCHR)
		write(1, "c", 1);
	else if ((mode & S_IFMT) == S_IFBLK)
		write(1, "b", 1);
	else if ((mode & S_IFMT) == S_IFLNK)
		write(1, "l", 1);
	else if ((mode & S_IFMT) == S_IFSOCK)
		write(1, "s", 1);
}

static void		print_chmod(mode_t mode)
{
	mode & S_IRUSR ? write(1, "r", 1) : write(1, "-", 1);
	mode & S_IWUSR ? write(1, "w", 1) : write(1, "-", 1);
	if (mode & S_ISUID)
		(mode & S_IXUSR) ?
			write(1, "s", 1) : write(1, "S", 1);
	else
		mode & S_IXUSR ? write(1, "x", 1) : write(1, "-", 1);
	mode & S_IRGRP ? write(1, "r", 1) : write(1, "-", 1);
	mode & S_IWGRP ? write(1, "w", 1) : write(1, "-", 1);
	if (mode & S_ISGID)
		(mode & S_IXGRP) ?
			write(1, "s", 1) : write(1, "S", 1);
	else
		mode & S_IXGRP ? write(1, "x", 1) : write(1, "-", 1);
	mode & S_IROTH ? write(1, "r", 1) : write(1, "-", 1);
	mode & S_IWOTH ? write(1, "w", 1) : write(1, "-", 1);
	if (mode & S_ISVTX)
		(mode & S_IXOTH) ?
			write(1, "t", 1) : write(1, "T", 1);
	else
		mode & S_IXOTH ? write(1, "x", 1) : write(1, "-", 1);
}

static void		long_dev(t_file *file, unsigned long flags, int ln)
{
	size_t			link;
	char			buf[100];

	print_type(file->mode);
	print_chmod(file->mode);
	print_acl(file->name);
	ft_printf("%*d ", ln, file->nlink);
	if (flags >> ('z' - 'n') & (unsigned long)1)
		ft_printf("%-4d %-5d ", file->uid, file->gid);
	else
		ft_printf("%-*s  %-*s  ", g_u_len, getpwuid(file->uid)->pw_name,
			g_g_len, getgrgid(file->gid)->gr_name);
	((file->mode & S_IFMT) == S_IFCHR || (file->mode & S_IFMT) == S_IFBLK) ?
	ft_printf("%4d, %3d ", MAJ(file->dev), MIN(file->dev)) :
	ft_printf("%9d ", file->size);
	ft_printf("%.2s %.3s %.5s ", ctime(&(file->time.tv_sec)) + 8, TM);
	ft_putstr(file->name);
	if ((file->mode & S_IFMT) == S_IFLNK)
	{
		link = readlink(file->path, buf, 100);
		ft_printf(" -> %.*s", link, buf);
	}
	write(1, "\n", 1);
}

static void		long_contin(t_file *file, unsigned long flags, int sz)
{
	size_t			link;
	char			buf[100];

	((file->mode & S_IFMT) == S_IFCHR || (file->mode & S_IFMT) == S_IFBLK) ?
		ft_printf("%4d, %3d ", MAJ(file->dev), MIN(file->dev)) :
			ft_printf("%*d ", sz, file->size);
	ft_printf("%.2s %.3s %.5s ", ctime(&(file->time.tv_sec)) + 8, TM);
	ft_putstr(file->name);
	((flags >> ('z' - 'p') & 1) && (file->mode & S_IFMT) == S_IFDIR) ?
		write(1, "/", 1) : 0;
	if ((file->mode & S_IFMT) == S_IFLNK)
	{
		link = readlink(file->path, buf, 100);
		ft_printf(" -> %.*s", link, buf);
	}
	write(1, "\n", 1);
}

void			long_format(t_file *file, unsigned long flags, int sz, int ln)
{
	if (*(file->name) == '.' && !(flags >> ('z' - 'a') & (unsigned long)1))
		return ;
	if (flags >> 62 & (unsigned long)1)
	{
		long_dev(file, flags, ln);
		return ;
	}
	print_type(file->mode);
	print_chmod(file->mode);
	print_acl(file->path);
	ft_printf("%*d ", ln, file->nlink);
	if (flags >> ('z' - 'n') & (unsigned long)1)
		ft_printf("%d  %d  ", file->uid, file->gid);
	else
		ft_printf("%-*s  %-*s  ", g_u_len, getpwuid(file->uid)->pw_name,
			g_g_len, getgrgid(file->gid)->gr_name);
	long_contin(file, flags, sz);
}
