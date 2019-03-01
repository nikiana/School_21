/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:00:59 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/27 22:23:15 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	free_file(t_file **file)
{
	int i;

	i = 0;
	while (file[i])
	{
		free(file[i]->name);
		free(file[i]->path);
		free(file[i]);
		i++;
	}
	free(file);
}
