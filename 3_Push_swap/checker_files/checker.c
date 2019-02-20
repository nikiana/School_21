/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:53:40 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 19:22:08 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			clean_all(t_list *a, t_list *b, t_flags *flag, char **res)
{
	t_list *tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	while (b)
	{
		tmp = b->next;
		free(b);
		b = tmp;
	}
	if (flag)
		free(flag);
	if (res)
		ft_free_arr(res);
	return (0);
}

int			error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int			get_nums(char *str, t_list **a)
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

static int	check_f(char *str)
{
	if (str[0] == '-' && str[1] && str[1] == 'f')
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	int			i;
	t_list		*a;
	t_list		*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (check_f(av[1]))
	{
		if (!read_from_file(&a, av[2]))
			return (clean_all(a, b, 0, 0)) ? 0 : 0;
	}
	else
	{
		i = 1;
		while (i < ac)
			if (!get_nums(av[i++], &a))
				return (clean_all(a, b, 0, 0)) ? 0 : 0;
	}
	read_instructions(&a, &b, 0);
	clean_all(a, b, 0, 0);
	return (0);
}
