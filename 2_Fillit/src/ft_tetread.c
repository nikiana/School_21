/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:34:19 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/11 19:50:51 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void		save(unsigned int num, t_lst **head, char a)
{
	size_t	i;
	size_t	j;
	int		ar[4];

	i = 1;
	j = 1;
	ar[0] = 0;
	while (j < 4)
	{
		if ((num >> 1) & (unsigned int)1)
			ar[j++] = i;
		num = num >> 1;
		i++;
	}
	push_back(head, ar, a);
}

static	int		ft_shapecheck(unsigned int num, t_lst **head, char a)
{
	if (num == 15 || num == 33825 || num == 1059 || num == 135 || num == 1569 ||
		num == 225 || num == 2115 || num == 57 || num == 3105 || num == 39 ||
		num == 99 || num == 195 || num == 561 || num == 51 || num == 2145 ||
		num == 113 || num == 1121 || num == 71 || num == 1073)
	{
		save(num, head, a);
		return (1);
	}
	return (0);
}

static	int		ft_buffcheck(char *str, t_lst **head, char a)
{
	size_t			i;
	size_t			j;
	size_t			sign;
	unsigned int	shape;

	i = 0;
	j = 0;
	shape = 0;
	while (str[i])
	{
		sign = 0;
		if ((((i + 1) % 5 == 0) || i == 20) && (str[i] != '\n'))
			return (0);
		else if ((((i + 1) % 5 != 0) && i != 20))
		{
			if (str[i] != '.' && str[i] == '#' && (sign = 1))
				shape |= (unsigned int)1 << j++;
			if (str[i] != '.' && str[i] != '#')
				break ;
		}
		i++;
		(j == 0 || sign) ? 1 : j++;
	}
	return ((ft_shapecheck(shape, head, a) && (i == 21 || i == 20)) ? 1 : 0);
}

int				ft_tetread(int fd, t_lst **head)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	a;

	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	a = 'A';
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (a > 'Z')
			return (0);
		buf[ret] = '\0';
		if (!(ft_buffcheck(buf, head, a)))
			return (0);
		a++;
	}
	if (buf[BUFF_SIZE - 1] == buf[BUFF_SIZE - 2])
		return (0);
	return (1);
}
