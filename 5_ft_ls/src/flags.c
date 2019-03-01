/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:56:03 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:44:14 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		check_flags(char *av, unsigned long *flags)
{
	int	i;

	i = 1;
	while (av[i] && ft_strchr(OPT, av[i]))
	{
		if (av[i] == '1')
		{
			*flags |= ((unsigned long)1 << 63);
			*flags &= ~((unsigned long)1 << 55);
			*flags &= ~((unsigned long)1 << ('z' - 'l'));
		}
		else
		{
			*flags |= (unsigned long)1 << ('z' - av[i]);
			if (av[i] == 'C')
				*flags &= ~((unsigned long)1 << 63);
			if (av[i] == 'n')
				*flags |= (unsigned long)1 << ('z' - 'l');
			if (av[i] == 'f')
				*flags |= (unsigned long)1 << ('z' - 'a');
		}
		i++;
	}
	return (av[i]) ? (opt_err(av[i])) : 0;
}
