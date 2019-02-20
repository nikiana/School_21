/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:06:38 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/23 21:17:45 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sa(t_list *a)
{
	int tmp;

	if (a && a->next)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
	}
}

void	sb(t_list *b)
{
	int tmp;

	if (b && b->next)
	{
		tmp = b->content;
		b->content = b->next->content;
		b->next->content = tmp;
	}
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
}

void	pa(t_list **b, t_list **a)
{
	if (*b)
	{
		ft_list_push_front(a, (*b)->content, 0);
		delete_element(0, b, (*b)->next);
	}
}

void	pb(t_list **a, t_list **b)
{
	if (*a)
	{
		ft_list_push_front(b, (*a)->content, 0);
		delete_element(0, a, (*a)->next);
	}
}
