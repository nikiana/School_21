/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:56:43 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:56:39 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		opt_err(char a)
{
	ft_printf("ls: illegal option -- %c\n\
usage: ls [-1aCflnpRrStz] [file ...]\n", a);
	return (1);
}

int		print_usage(void)
{
	ft_printf("Usage: ft_ls [-1aCflpRrStz] [file ...]\n\
	-1: Force output to be one entry per line.\n\
	-a: Include directory entries whose names begin with a dot ('.').\n\
	-C: Force multi-column output.\n\
	-f: Output is not sorted. This option implies -a.\n\
	-l: List in long format.\n\
	-n: Display user and group IDs numerically. This \
option turns on the -l option.\n\
	-p: Display a slash after each pathname that is a directory.\n\
	-R: Recursively list subdirectories encountered.\n\
	-r: Reverse the order of the sort.\n\
	-S: Sort by size, largest file first.\n\
	-t: Sort by time modified (most recently modified first)\n\
	-z : Show all valid options\n");
	return (0);
}
