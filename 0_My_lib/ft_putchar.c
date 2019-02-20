/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:30:57 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/07 18:30:03 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	help_puchar(int c)
{
	unsigned char cc;

	if (c <= 65535)
	{
		cc = 224 + c / 4096;
		write(1, &cc, 1);
		c %= 4096;
		cc = 128 + c / 64;
		write(1, &cc, 1);
		cc = 128 + c % 64;
		write(1, &cc, 1);
	}
	else if (c <= 2097151)
	{
		cc = 240 + c / 32768;
		write(1, &cc, 1);
		c %= 32768;
		cc = 128 + c / 4096;
		write(1, &cc, 1);
		c %= 4096;
		cc = 128 + c / 64;
		write(1, &cc, 1);
		cc = 128 + c % 64;
		write(1, &cc, 1);
	}
}

void		ft_putchar(int c)
{
	unsigned char cc;

	if (c >= 0 && c <= 255)
	{
		cc = c;
		write(1, &cc, 1);
	}
	else if (c <= 2047)
	{
		cc = 192 + c / 64;
		write(1, &cc, 1);
		cc = 128 + c % 64;
		write(1, &cc, 1);
	}
	else
		help_puchar(c);
}
