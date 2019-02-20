/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:40:41 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/16 14:24:57 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_color(t_point ***map, t_glob *glob)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x]->z < 0)
				map[y][x]->color = LOWEST;
			else if (map[y][x]->z <= glob->max_val / 3)
				map[y][x]->color = LOW;
			else if (map[y][x]->z >= glob->max_val / 3 * 2)
				map[y][x]->color = TOP;
			else
				map[y][x]->color = MEDIUM;
			x++;
		}
		y++;
	}
}

static int		get_dimensions(t_glob *glob, int fd)
{
	char *res;
	char **split;

	if (get_next_line(fd, &res) == -1)
		return (1);
	split = ft_strsplit(res, ' ');
	while (*split)
	{
		glob->max_x++;
		glob->map_width++;
		split++;
	}
	free(res);
	ft_free_arr(split - glob->max_x - 1);
	while (get_next_line(fd, &res))
	{
		glob->max_y++;
		glob->map_height++;
		free(res);
	}
	return (0);
}

static t_point	***save_map(t_glob *glob, int fd, int x, int y)
{
	char	*line;
	char	**split;
	t_point ***res;

	res = (t_point***)malloc(sizeof(t_point) * glob->map_height + 1);
	while (get_next_line(fd, &line))
	{
		res[y] = (t_point **)malloc(sizeof(t_point) * glob->map_width + 1);
		x = 0;
		split = ft_strsplit(line, ' ');
		while (split[x])
		{
			res[y][x] = new_point(x, y, ft_atoi(split[x]));
			if (res[y][x]->z > glob->max_val)
				glob->max_val = res[y][x]->z;
			x++;
		}
		res[y++][x] = NULL;
		free(line);
		ft_free_arr(split);
	}
	res[y] = NULL;
	return (res);
}

t_point			***get_map(char *file, t_glob *glob)
{
	int		fd;
	t_point	***res;

	fd = open(file, O_RDONLY);
	if (get_dimensions(glob, fd))
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	res = save_map(glob, fd, 0, 0);
	get_color(res, glob);
	close(fd);
	return (res);
}

t_point			***map_copy(t_point ***map, t_glob *glob)
{
	int		x;
	int		y;
	t_point	***res;

	res = (t_point***)malloc(sizeof(t_point) * glob->map_height + 1);
	y = 0;
	while (map[y])
	{
		res[y] = (t_point **)malloc(sizeof(t_point) * glob->map_width + 1);
		x = 0;
		while (map[y][x])
		{
			res[y][x] = new_point(map[y][x]->x, map[y][x]->y, map[y][x]->z);
			res[y][x]->color = map[y][x]->color;
			x++;
		}
		res[y++][x] = NULL;
	}
	res[y] = NULL;
	return (res);
}
