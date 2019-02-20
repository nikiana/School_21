/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:58:34 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:09:54 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x(int step, t_point ***map, t_glob *glob)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x]->x += step;
			x++;
		}
		y++;
	}
	glob->max_x += step;
	glob->min_x += step;
}

void	move_y(int step, t_point ***map, t_glob *glob)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x]->y += step;
			x++;
		}
		y++;
	}
	glob->max_y += step;
	glob->min_y += step;
}
