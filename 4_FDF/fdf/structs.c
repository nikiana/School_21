/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:24:42 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:09:57 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(float x, float y, float z)
{
	t_point *a;

	a = (t_point*)malloc(sizeof(t_point));
	a->x = x;
	a->y = y;
	a->z = z;
	return (a);
}

t_point	**new_line(t_point *a, t_point *b)
{
	t_point **res;

	res = (t_point**)malloc(sizeof(t_point*) * 2);
	res[0] = a;
	res[1] = b;
	return (res);
}

t_glob	*new_glob(void *mlx_ptr, void *win_ptr)
{
	t_glob *res;

	res = (t_glob*)malloc(sizeof(t_glob));
	res->mlx_ptr = malloc(sizeof(mlx_ptr));
	res->mlx_ptr = mlx_ptr;
	res->win_ptr = malloc(sizeof(win_ptr));
	res->win_ptr = win_ptr;
	res->map_height = 1;
	res->map_width = 0;
	res->max_val = 0;
	res->min_x = 0;
	res->min_y = 0;
	res->max_x = -1;
	res->max_y = 0;
	res->cam_x = 0;
	res->cam_y = 0;
	res->cam_z = 0;
	res->cam_zoom = 1;
	res->menu = 1;
	return (res);
}

t_param	*new_param(t_point ***map, t_glob *glob)
{
	t_param *res;

	res = (t_param*)malloc(sizeof(t_param));
	res->glob = malloc(sizeof(glob));
	res->map = malloc(sizeof(map));
	res->top_v = malloc(sizeof(map));
	res->glob = glob;
	res->map = map;
	return (res);
}

void	free_map(t_point ***map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			free(map[y][x]);
			x++;
		}
		free(map[y]);
		y++;
	}
	free(map);
}
