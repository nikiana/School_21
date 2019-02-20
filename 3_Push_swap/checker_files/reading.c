/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:06:08 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 19:20:43 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			read_from_file(t_list **a, char *file)
{
	int		fd;
	int		i;
	char	*str;
	char	**res;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (error());
	get_next_line(fd, &str);
	res = ft_strsplit(str, ' ');
	while (res[i])
	{
		if (!get_nums(res[i], a))
			return (0);
		i++;
	}
	close(fd);
	ft_free_arr(res);
	free(str);
	return (1);
}

static int	reading_r(t_list **a, t_list **b, char buf[1], int *sign)
{
	read(0, buf, 1);
	if (buf[0] == 'a')
		ra(a);
	else if (buf[0] == 'b')
		rb(b);
	else if (buf[0] == 'r')
	{
		read(0, buf, 1);
		if (buf[0] == 'a')
			rra(a);
		else if (buf[0] == 'b')
			rrb(b);
		else if (buf[0] == 'r')
			rrr(a, b);
		else if (buf[0] == '\n')
		{
			*sign = 1;
			rr(a, b);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	reading_s_p(t_list **a, t_list **b, char buf[1])
{
	if (buf[0] == 's')
	{
		read(0, buf, 1);
		if (buf[0] == 'a')
			sa(*a);
		else if (buf[0] == 'b')
			sb(*b);
		else if (buf[0] == 's')
			ss(*a, *b);
		else
			return (0);
	}
	else if (buf[0] == 'p')
	{
		read(0, buf, 1);
		if (buf[0] == 'a')
			pa(b, a);
		else if (buf[0] == 'b')
			pb(a, b);
		else
			return (0);
	}
	return (1);
}

int			read_instructions(t_list **a, t_list **b, int sign)
{
	char buf[1];

	while (read(0, buf, 1))
	{
		if (buf[0] == 4)
			break ;
		else if (buf[0] == 's' || buf[0] == 'p')
		{
			if (!reading_s_p(a, b, buf))
				return (error());
		}
		else if (buf[0] == 'r')
		{
			if (!reading_r(a, b, buf, &sign))
				return (error());
		}
		else
			return (error());
		sign ? 1 : read(0, buf, 1);
		if (buf[0] != '\n')
			return (error());
		sign = 0;
	}
	(is_sorted(*a) && !*b) ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
	return (0);
}
