/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_and_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:12:26 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 18:39:13 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int		clean_all(t_list *a, t_list *b, t_flags *flag, char **res)
{
	t_list *tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	while (b)
	{
		tmp = b->next;
		free(b);
		b = tmp;
	}
	if (flag)
		free(flag);
	if (res)
		ft_free_arr(res);
	return (0);
}

void	delete_element(t_list *prev, t_list **elem, t_list *next)
{
	free(*elem);
	*elem = NULL;
	if (prev && next)
		prev->next = next;
	else if (next)
		*elem = next;
}

void	p_rrr(t_list **a, t_list **b, t_flags *flag)
{
	t_list *last;

	if (*a && (*a)->next)
	{
		last = *a;
		while (last->next->next)
			last = last->next;
		ft_list_push_front(a, last->next->content, last->next->index);
		delete_element(last, &(last->next), 0);
	}
	if (*b && (*b)->next)
	{
		last = *b;
		while (last->next->next)
			last = last->next;
		ft_list_push_front(b, last->next->content, last->next->index);
		delete_element(last, &(last->next), 0);
	}
	ft_putendl("rrr");
	flag->count++;
	if (flag->w)
		print_stack(*a, *b, flag);
}
