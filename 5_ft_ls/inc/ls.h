/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:59:12 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 23:09:42 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <time.h>
# include <sys/ioctl.h>
# include "libft.h"

# define OPT "RlC1antrSfpz"
# define MAJ(x)	((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define MIN(x)	((int32_t)((x) & 0xffffff))
# define TM ctime(&(file->time.tv_sec)) + 4, ctime(&(file->time.tv_sec)) + 11

typedef struct	s_file
{
	char			*path;
	char			*name;
	unsigned short	name_len;
	mode_t			mode;
	nlink_t			nlink;
	struct timespec	time;
	off_t			size;
	uid_t			uid;
	gid_t			gid;
	dev_t			dev;
}				t_file;

int				g_arg;
int				g_u_len;
int				g_g_len;

int				check_flags(char *av, unsigned long *flags);
t_file			**parse_args(int ac, char **av, t_file **dirs,
					unsigned long fl);

void			show_files(unsigned long flags, t_file **files, int i, int si);
int				show_dirs(t_file **files, unsigned long flags);
int				show_dev(t_file ***fl, unsigned long flags, int i);

void			long_format(t_file *file, unsigned long flags, int sz, int ln);
void			print_acl(char *file);

void			sort_files(unsigned long flags, t_file **files);
void			sort_size(t_file **files, unsigned long flags);
void			sort_time(t_file **files, unsigned long flags);
void			sort_args(t_file **fls, unsigned long flag);

int				opt_err(char a);
int				print_usage(void);
void			count_g_len(t_file **files);

void			swap(t_file **fls, int one, int two);
int				find_max(t_file **files, int *i);

void			free_file(t_file **file);

#endif
