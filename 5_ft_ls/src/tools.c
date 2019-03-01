/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:30:05 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 23:03:08 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		find_max(t_file **files, int *i)
{
	int	max;

	max = 0;
	*i = 0;
	while (files[*i])
	{
		if (files[*i]->name_len > max)
			max = files[*i]->name_len;
		(*i)++;
	}
	return (++max);
}

void	print_acl(char *file)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;

	acl = acl_get_link_np(file, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(file, 0, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		write(1, "@", 1);
	else if (acl != NULL)
		write(1, "+", 1);
	else
		write(1, " ", 1);
	write(1, " ", 1);
}

void	count_g_len(t_file **files)
{
	int	i;
	int tmp;

	i = 0;
	g_u_len = 0;
	g_g_len = 0;
	while (files[i])
	{
		tmp = ft_strlen(getpwuid(files[i]->uid)->pw_name);
		if (tmp > g_u_len)
			g_u_len = tmp;
		tmp = ft_strlen(getgrgid(files[i]->gid)->gr_name);
		if (tmp > g_g_len)
			g_g_len = tmp;
		i++;
	}
}
