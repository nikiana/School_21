/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:06:38 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 13:31:06 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ra(t_list **a)
{
	if (*a && (*a)->next)
	{
		ft_list_push_back(a, (*a)->content, 0);
		delete_element(0, a, (*a)->next);
	}
}

void	rb(t_list **b)
{
	if (*b && (*b)->next)
	{
		ft_list_push_back(b, (*b)->content, 0);
		delete_element(0, b, (*b)->next);
	}
}

void	rra(t_list **a)
{
	t_list *last;

	if (*a && (*a)->next)
	{
		last = *a;
		while (last->next->next)
			last = last->next;
		ft_list_push_front(a, last->next->content, 0);
		delete_element(last, &(last->next), 0);
	}
}

void	rrb(t_list **b)
{
	t_list *last;

	if (*b && (*b)->next)
	{
		last = *b;
		while (last->next->next)
			last = last->next;
		ft_list_push_front(b, last->next->content, 0);
		delete_element(last, &(last->next), 0);
	}
}
