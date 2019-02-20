/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:14:22 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:09:58 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_point ***map, double n, t_glob *glob, int zoom)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x]->x *= n;
			map[y][x]->y *= n;
			map[y][x]->z *= n;
			x++;
		}
		y++;
	}
	glob->min_x *= n;
	glob->min_y *= n;
	glob->max_x *= n;
	glob->max_y *= n;
	if (zoom)
		glob->cam_zoom *= n;
}

void	change_altitude(t_point ****map, t_glob *glob, double n,
t_point ***top_v)
{
	int x;
	int y;

	y = 0;
	while (top_v[y])
	{
		x = 0;
		while (top_v[y][x])
		{
			top_v[y][x]->z *= n;
			x++;
		}
		y++;
	}
	if (map && *map)
	{
		free_map(*map);
		*map = map_copy(top_v, glob);
		rotate_x(*map, glob->cam_x, glob);
		rotate_y(*map, glob->cam_y, glob);
		rotate_z(*map, glob->cam_z, glob);
		scale(*map, glob->cam_zoom, glob, 0);
	}
}

void	centring(t_point ***map, t_glob *glob, int x_cent, int y_cent)
{
	int x;
	int y;
	int move_w;
	int move_h;

	x_cent = glob->min_x + (glob->max_x - glob->min_x) / 2;
	y_cent = glob->min_y + (glob->max_y - glob->min_y) / 2;
	move_w = FRAME_SCR_W / 2 - x_cent;
	move_h = FRAME_SCR_H / 2 - y_cent;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x]->x += move_w;
			map[y][x]->y += move_h;
			x++;
		}
		y++;
	}
	glob->max_x += move_w;
	glob->max_y += move_h;
	glob->min_x += move_w;
	glob->min_y += move_h;
}
