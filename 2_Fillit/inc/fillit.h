/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:34:47 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/12 15:46:15 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21
# define X (map->coord)
# define E(a) ((X[a] / 5) * (n + 1) + (X[a] % 5))
# define IND0 (0)
# define IND1 (X[1] == 3 || X[1] == 4) ? (n - X[1] % 2) : E(1)
# define IND2 (X[2] == 9 || X[2] == 4) ? ((X[2] / 9) + n * (X[2] / 4)) : E(2)
# define IND3 (X[3] == 9) ? (n * 2 + 1) : E(3)

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_lst
{
	int				*coord;
	char			ltr;
	struct s_lst	*next;
}					t_lst;

t_lst				*lstnew(int *coord, char a);
t_lst				*push_back(t_lst **begin_list, int *coord, char a);
void				free_lst(t_lst **head);
int					lst_size(t_lst *begin_list);
char				*strnew(int n);
int					ft_sqrt(int nb);
int					smallest_sqr(t_lst *head);
void				ft_solve(t_lst *head, char **res);
int					ft_tetread(int fd, t_lst **head);

#endif
