/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:36:56 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 14:17:07 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			check_flags(char *str, t_flags *flag)
{
	int i;

	i = 1;
	flag->c = 0;
	flag->w = 0;
	flag->s = 0;
	flag->f = 0;
	flag->count = 0;
	if (str[0] != '-' || !str[1])
		return (0);
	while (str[i])
	{
		if (str[i] != 'c' && str[i] != 'w' && str[i] != 's' && str[i] != 'f')
			return (0);
		i++;
	}
	if (ft_strchr(str, 'c'))
		flag->c = 1;
	if (ft_strchr(str, 'w'))
		flag->w = 1;
	if (ft_strchr(str, 's'))
		flag->s = 1;
	if (ft_strchr(str, 'f'))
		flag->f = 1;
	return (1);
}

static void	help_print_stack(t_list *a, t_flags *flag)
{
	int min;
	int max;

	find_min(a, &min);
	find_max(a, &max);
	if (!a)
		ft_putstr("*Empty*\n");
	while (a)
	{
		if (a->content == min || a->content == max)
			if (flag->c)
				(a->content == min) ? ft_putstr("\033[0;32m") :
				ft_putstr("\033[0;31m");
		ft_putnbr(a->content);
		ft_putstr("\033[0m");
		ft_putchar(' ');
		a = (a)->next;
	}
	ft_putstr("\n");
}

void		print_stack(t_list *a, t_list *b, t_flags *flag)
{
	ft_putstr("\033[4;37m");
	ft_putstr("\nSTACK 'A':\n");
	ft_putstr("\033[0m");
	help_print_stack(a, flag);
	ft_putstr("\033[4;37m");
	ft_putstr("\nSTACK 'B':\n");
	ft_putstr("\033[0m");
	help_print_stack(b, flag);
	ft_putstr("\n");
}

void		total_steps_num(t_flags *flag)
{
	if (flag->s)
	{
		ft_putstr("\n\nTOTAL NUMBER OF COMMANDS: ");
		ft_putnbr(flag->count);
		ft_putstr("\n");
	}
}
