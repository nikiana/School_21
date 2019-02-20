/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:40:42 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/12 15:46:32 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		fd;
	t_lst	*head;
	char	*res;

	res = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (1);
	if (ft_tetread(fd, &head) <= 0 || !head)
	{
		ft_putendl("error");
		free_lst(&head);
		return (1);
	}
	ft_solve(head, &res);
	free_lst(&head);
	close(fd);
	return (0);
}
