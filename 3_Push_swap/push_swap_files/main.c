/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:34:00 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 19:21:10 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void		solving(t_list **a, t_list **b, t_flags *flag)
{
	int i;

	i = ft_list_size(*a);
	if (!is_sorted(*a))
	{
		if (i <= 3)
			sort_small(a, b, i, flag);
		else if (i < 10)
			sort_medium(a, b, i, flag);
		else
			sort_large(a, b, i, flag);
	}
}

int				get_nums(char *str, t_list **a)
{
	char		**res;
	int			i;
	int			j;
	long int	num;

	res = ft_strsplit(str, ' ');
	j = 0;
	while (res[j])
	{
		i = 0;
		while (res[j][i])
		{
			if ((res[j][i] < '0' || res[j][i] > '9') &&
			(i != 0 || res[j][i] != '-'))
				return (clean_all(0, 0, 0, res)) ? (error()) : (error());
			i++;
		}
		num = ft_atoi(res[j]);
		if (!is_valid(*a, num))
			return (clean_all(0, 0, 0, res)) ? (error()) : (error());
		ft_list_push_back(a, num, 0);
		j++;
	}
	ft_free_arr(res);
	return (1);
}

int				read_from_file(t_list **a, char *file)
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

static int		reading(t_list **a, t_flags *flag, char **av, int ac)
{
	int i;

	if (!flag->f)
	{
		i = 2;
		if (!flag->w && !flag->c && !flag->s && !flag->f)
			i = 1;
		while (i < ac)
		{
			if (!get_nums(av[i], a))
				return (0);
			i++;
		}
	}
	else
	{
		if (!read_from_file(a, av[2]))
			return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	int			i;
	t_flags		*flag;
	t_list		*a;
	t_list		*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	flag = (t_flags*)malloc(sizeof(t_flags));
	i = 1;
	if (check_flags(av[1], flag))
		i = 2;
	if (!reading(&a, flag, av, ac))
		return (clean_all(a, b, flag, 0)) ? 0 : 0;
	solving(&a, &b, flag);
	total_steps_num(flag);
	clean_all(a, b, flag, 0);
	return (0);
}
