/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:23:35 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/12 15:46:13 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_lst	*lstnew(int *coord, char a)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	new->next = NULL;
	new->ltr = a;
	if (!(new->coord = ft_memalloc(sizeof(int) * 4)))
	{
		free(new);
		return (NULL);
	}
	if (!coord)
		ft_bzero(new->coord, 16);
	else
		ft_memcpy(new->coord, coord, 16);
	return (new);
}

t_lst	*push_back(t_lst **begin_list, int *coord, char a)
{
	t_lst *tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lstnew(coord, a);
		return (tmp->next);
	}
	*begin_list = lstnew(coord, a);
	return (*begin_list);
}

int		lst_size(t_lst *begin_list)
{
	int		i;
	t_lst	*p;

	i = 0;
	p = begin_list;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

void	free_lst(t_lst **head)
{
	t_lst *tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->coord);
		free(*head);
		*head = tmp;
	}
}
