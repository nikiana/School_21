/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:45:30 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:25:44 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define FRAME_SCR_W 2560
# define FRAME_SCR_H 1250
# define LOWEST 0X435CFA
# define LOW 0XFFFFFF
# define MEDIUM 0xFFAB61
# define TOP 16723712

typedef struct	s_glob
{
	void		*mlx_ptr;
	void		*win_ptr;
	short int	map_width;
	short int	map_height;
	short int	min_x;
	short int	max_x;
	short int	min_y;
	short int	max_y;
	float		max_val;
	float		cam_x;
	float		cam_y;
	float		cam_z;
	float		cam_zoom;
	short int	menu;
}				t_glob;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	int			color;

}				t_point;

typedef struct	s_param
{
	t_glob		*glob;
	t_point		***map;
	t_point		***top_v;
}				t_param;

t_point			**new_line(t_point *a, t_point *b);

t_point			*new_point(float x, float y, float z);

t_glob			*new_glob(void *mlx_ptr, void *win_ptr);

t_param			*new_param(t_point ***map, t_glob *glob);

void			draw_map(t_point ***map, t_glob *glob);

void			clear_map(t_point ***map, t_glob *glob);

void			free_map(t_point ***map);

t_point			***map_copy(t_point ***map, t_glob *glob);

void			draw_menu(t_glob *glob);

void			scale(t_point ***map, double n, t_glob *glob, int zoom);

void			centring(t_point ***map, t_glob *glob, int	x_cent, int y_cent);

void			change_altitude(t_point ****map, t_glob *glob, double n,
t_point ***top_v);

t_point			***get_map(char *file, t_glob *glob);

void			make_izo(t_point ***map, t_glob *glob);

void			rotate_x(t_point ***map, float ang, t_glob *glob);

void			rotate_y(t_point ***map, float ang, t_glob *glob);

void			rotate_z(t_point ***map, float ang, t_glob *glob);

int				key_press(int keycode, t_param *param);

int				mouse_press(int button, int x, int y, t_param *param);

void			move_x(int step, t_point ***map, t_glob *glob);

void			move_y(int step, t_point ***map, t_glob *glob);

#endif
