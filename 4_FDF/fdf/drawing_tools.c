/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:35:21 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:25:18 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_point a, t_point b, t_glob *glob, int steps)
{
	float		dx;
	float		dy;
	short int	x_step;
	short int	y_step;
	int			error;

	dx = fabsf(b.x - a.x);
	dy = fabsf(b.y - a.y);
	steps = (dx > dy) ? dx : dy;
	x_step = (b.x > a.x) ? 1 : -1;
	y_step = (b.y > a.y) ? 1 : -1;
	error = dx - dy;
	while (steps--)
	{
		if (a.y < 1250)
			mlx_pixel_put(glob->mlx_ptr, glob->win_ptr, a.x, a.y, a.color);
		if (error * 2 > -dy)
			a.x += (error -= dy) ? x_step : x_step;
		if (error * 2 < dx)
			a.y += (error += dx) ? y_step : y_step;
	}
}

static void	draw_line_menu(t_point a, t_point b, int color, t_glob *glob)
{
	float		dx;
	float		dy;
	short int	x_step;
	short int	y_step;
	int			error;

	dx = fabsf(b.x - a.x);
	dy = fabsf(b.y - a.y);
	x_step = (b.x > a.x) ? 1 : -1;
	y_step = (b.y > a.y) ? 1 : -1;
	error = dx - dy;
	while (1)
	{
		mlx_pixel_put(glob->mlx_ptr, glob->win_ptr, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		if (error * 2 > -dy)
			a.x += (error -= dy) ? x_step : x_step;
		if (error * 2 < dx)
			a.y += (error += dx) ? y_step : y_step;
	}
}

void		draw_map(t_point ***map, t_glob *glob)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] && map[y + 1])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x + 1])
				draw_line(*(map[y][x]), *(map[y][x + 1]), glob, 0);
			draw_line(*(map[y][x]), *(map[y + 1][x]), glob, 0);
			x++;
		}
		y++;
	}
	x = 0;
	while (map[y][x] && map[y][x + 1])
	{
		draw_line(*(map[y][x]), *(map[y][x + 1]), glob, 0);
		x++;
	}
}

static void	draw_sq(int color, t_glob *glob)
{
	t_point	*a;
	t_point	*b;

	a = new_point(0, 1250, 0);
	b = new_point(2560, 1250, 0);
	while (a->y != 1395)
	{
		draw_line_menu(*a, *b, color, glob);
		a->y++;
		b->y++;
	}
}

void		draw_menu(t_glob *glob)
{
	draw_sq(0X505B66, glob);
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 1000, 1260, 0XFFFFFF,
	"Press 'm' to hide the menu and speed up the map");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 300, 1300, 0XFFFFFF,
	"Izometric view: '1'");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 300, 1330, 0XFFFFFF,
	"Top view: '2'");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 300, 1360,
	0XFFFFFF, "Amplitude: +/-");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 1130, 1300,
	0XFFFFFF, "X-axis rotatiom: W/S");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 1130, 1330,
	0XFFFFFF, "Y-axis rotatiom: A/D");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 1130, 1360,
	0XFFFFFF, "Z-axis rotatiom: Q/E");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 1900, 1300,
	0XFFFFFF, "Zoom in/out: scroll wheel");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 1900, 1330,
	0XFFFFFF, "Moving right/left/up/down: arrow keys");
	mlx_string_put(glob->mlx_ptr, glob->win_ptr, 1900, 1360,
	0XFFFFFF, "Exit: Esc");
}
