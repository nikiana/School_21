/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:12:26 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 13:31:15 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	delete_element(t_list *prev, t_list **elem, t_list *next)
{
	free(*elem);
	*elem = NULL;
	if (prev && next)
		prev->next = next;
	else if (next)
		*elem = next;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
