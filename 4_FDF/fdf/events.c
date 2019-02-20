/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:20:39 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:30:46 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_1(int keycode, t_param *param)
{
	if (keycode == 18)
	{
		mlx_clear_window(param->glob->mlx_ptr, param->glob->win_ptr);
		free_map(param->map);
		param->map = map_copy(param->top_v, param->glob);
		make_izo(param->map, param->glob);
		centring(param->map, param->glob, 0, 0);
		param->glob->cam_zoom = 1;
		if (param->glob->menu)
			draw_menu(param->glob);
		draw_map(param->map, param->glob);
	}
	if (keycode == 19)
	{
		mlx_clear_window(param->glob->mlx_ptr, param->glob->win_ptr);
		free_map(param->map);
		param->map = map_copy(param->top_v, param->glob);
		param->glob->cam_zoom = 1;
		if (param->glob->menu)
			draw_menu(param->glob);
		draw_map(param->map, param->glob);
		param->glob->cam_x = 0;
		param->glob->cam_y = 0;
		param->glob->cam_z = 0;
	}
}

static void	key_2(int keycode, t_param *param)
{
	mlx_clear_window(param->glob->mlx_ptr, param->glob->win_ptr);
	if (keycode == 12 || keycode == 14)
	{
		rotate_z(param->map, (keycode == 12) ? -0.1 : 0.1, param->glob);
		param->glob->cam_z += (keycode == 12) ? -0.1 : 0.1;
	}
	if (keycode == 0 || keycode == 2)
	{
		rotate_y(param->map, (keycode == 0) ? -0.1 : 0.1, param->glob);
		param->glob->cam_y += (keycode == 0) ? -0.1 : 0.1;
	}
	if (keycode == 1 || keycode == 13)
	{
		rotate_x(param->map, (keycode == 13) ? -0.1 : 0.1, param->glob);
		param->glob->cam_x += (keycode == 13) ? -0.1 : 0.1;
	}
	centring(param->map, param->glob, 0, 0);
	if (param->glob->menu)
		draw_menu(param->glob);
	draw_map(param->map, param->glob);
}

static void	key_3(int keycode, t_param *param)
{
	mlx_clear_window(param->glob->mlx_ptr, param->glob->win_ptr);
	if (keycode == 123)
		move_x(-5, param->map, param->glob);
	if (keycode == 124)
		move_x(5, param->map, param->glob);
	if (keycode == 125)
		move_y(5, param->map, param->glob);
	if (keycode == 126)
		move_y(-5, param->map, param->glob);
	if (keycode == 69)
	{
		change_altitude(&param->map, param->glob, 1.1, param->top_v);
		centring(param->map, param->glob, 0, 0);
	}
	if (keycode == 78)
	{
		change_altitude(&param->map, param->glob, 0.9, param->top_v);
		centring(param->map, param->glob, 0, 0);
	}
	if (param->glob->menu)
		draw_menu(param->glob);
	draw_map(param->map, param->glob);
}

int			key_press(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 46)
	{
		if (param->glob->menu)
		{
			param->glob->menu = 0;
			mlx_clear_window(param->glob->mlx_ptr, param->glob->win_ptr);
			draw_map(param->map, param->glob);
		}
		else
		{
			param->glob->menu = 1;
			draw_menu(param->glob);
		}
	}
	if (keycode == 18 || keycode == 19)
		key_1(keycode, param);
	if (keycode == 0 || keycode == 2 || keycode == 12 || keycode == 14 ||
	keycode == 1 || keycode == 13)
		key_2(keycode, param);
	if ((keycode >= 123 && keycode <= 126) || keycode == 69 || keycode == 78)
		key_3(keycode, param);
	return (0);
}

int			mouse_press(int button, int x, int y, t_param *param)
{
	if (x < 0 || y < 0)
		return (1);
	if (button == 4)
	{
		mlx_clear_window(param->glob->mlx_ptr, param->glob->win_ptr);
		scale(param->map, 1.5, param->glob, 1);
		centring(param->map, param->glob, 0, 0);
		if (param->glob->menu)
			draw_menu(param->glob);
		draw_map(param->map, param->glob);
	}
	if (button == 5)
	{
		mlx_clear_window(param->glob->mlx_ptr, param->glob->win_ptr);
		scale(param->map, 0.5, param->glob, 1);
		centring(param->map, param->glob, 0, 0);
		if (param->glob->menu)
			draw_menu(param->glob);
		draw_map(param->map, param->glob);
	}
	return (0);
}
