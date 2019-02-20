/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:34:17 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:09:56 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_point ***map, float ang, t_glob *glob)
{
	int		x;
	int		y;
	float	save_z;
	float	save_y;

	glob->max_y = 0;
	glob->min_y = 1395;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			save_z = map[y][x]->z;
			save_y = map[y][x]->y;
			map[y][x]->y = save_y * cos(ang) + save_z * sin(ang);
			map[y][x]->z = -save_y * sin(ang) + save_z * cos(ang);
			if (map[y][x]->y > glob->max_y)
				glob->max_y = map[y][x]->y;
			if (map[y][x]->y < glob->min_y)
				glob->min_y = map[y][x]->y;
			x++;
		}
		y++;
	}
}

void		rotate_y(t_point ***map, float ang, t_glob *glob)
{
	int		x;
	int		y;
	float	save_z;
	float	save_x;

	glob->max_x = 0;
	glob->min_x = 2560;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			save_z = map[y][x]->z;
			save_x = map[y][x]->x;
			map[y][x]->x = save_x * cos(ang) + save_z * sin(ang);
			map[y][x]->z = -save_x * sin(ang) + save_z * cos(ang);
			if (glob->max_x < map[y][x]->x)
				glob->max_x = map[y][x]->x;
			if (glob->min_x > map[y][x]->x)
				glob->min_x = map[y][x]->x;
			x++;
		}
		y++;
	}
}

static void	rotate_z_help(t_point ***map, float ang, t_glob *glob, int y)
{
	int		x;
	float	save_x;
	float	save_y;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			save_x = map[y][x]->x;
			save_y = map[y][x]->y;
			map[y][x]->x = save_x * cos(ang) - save_y * sin(ang);
			if (glob->max_x < map[y][x]->x)
				glob->max_x = map[y][x]->x;
			if (glob->min_x > map[y][x]->x)
				glob->min_x = map[y][x]->x;
			map[y][x]->y = save_x * sin(ang) + save_y * cos(ang);
			if (map[y][x]->y > glob->max_y)
				glob->max_y = map[y][x]->y;
			if (map[y][x]->y < glob->min_y)
				glob->min_y = map[y][x]->y;
			x++;
		}
		y++;
	}
}

void		rotate_z(t_point ***map, float ang, t_glob *glob)
{
	glob->max_x = 0;
	glob->min_x = 2560;
	glob->max_y = 0;
	glob->min_y = 1395;
	rotate_z_help(map, ang, glob, 0);
}

void		make_izo(t_point ***map, t_glob *glob)
{
	rotate_x(map, -0.615472907, glob);
	rotate_y(map, -0.785398, glob);
	rotate_z(map, 0.615472907, glob);
	glob->cam_x = -0.615472907;
	glob->cam_y = -0.785398;
	glob->cam_z = 0.615472907;
}
