/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:16:34 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:11:15 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	error(int i)
{
	if (i == 0)
		ft_putendl("Usage: ./fdf file_name");
	if (i == 1)
		ft_putendl("Error: Minilibx failed to create a window");
	if (i == 2)
		ft_putendl("Invalid file");
	return (-1);
}

static int	main_continue(t_point ***cur_map, t_glob *glob,
void *mlx_ptr, void *win_ptr)
{
	t_param	*param;
	t_point	***top_view;

	param = new_param(cur_map, glob);
	top_view = map_copy(cur_map, glob);
	param->top_v = top_view;
	draw_menu(glob);
	make_izo(cur_map, glob);
	centring(cur_map, glob, 0, 0);
	draw_map(cur_map, glob);
	mlx_hook(win_ptr, 2, 0, key_press, param);
	mlx_hook(win_ptr, 4, 0, mouse_press, param);
	mlx_loop(mlx_ptr);
	return (0);
}

int			main(int ac, char **av)
{
	t_point	***cur_map;
	t_glob	*glob;
	void	*mlx_ptr;
	void	*win_ptr;

	if (ac != 2)
		return (error(0));
	if (!(mlx_ptr = mlx_init()) ||
	!(win_ptr = mlx_new_window(mlx_ptr, 2560, 1395, "Tinky-winky")))
		return (error(1));
	glob = new_glob(mlx_ptr, win_ptr);
	if (!(cur_map = get_map(av[1], glob)))
		return (error(2));
	scale(cur_map, 20, glob, 0);
	centring(cur_map, glob, 0, 0);
	return (main_continue(cur_map, glob, mlx_ptr, win_ptr));
}
