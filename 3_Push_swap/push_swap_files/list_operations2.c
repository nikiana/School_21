/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:06:38 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 14:20:06 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	p_ra(t_list **a, t_list *b, t_flags *flag)
{
	if (*a && (*a)->next)
	{
		ft_list_push_back(a, (*a)->content, (*a)->index);
		delete_element(0, a, (*a)->next);
	}
	ft_putendl("ra");
	flag->count++;
	if (flag->w)
		print_stack(*a, b, flag);
}

void	p_rb(t_list *a, t_list **b, t_flags *flag)
{
	if (*b && (*b)->next)
	{
		ft_list_push_back(b, (*b)->content, (*b)->index);
		delete_element(0, b, (*b)->next);
	}
	ft_putendl("rb");
	flag->count++;
	if (flag->w)
		print_stack(a, *b, flag);
}

void	p_rr(t_list **a, t_list **b, t_flags *flag)
{
	if (*a && (*a)->next)
	{
		ft_list_push_back(a, (*a)->content, (*a)->index);
		delete_element(0, a, (*a)->next);
	}
	if (*b && (*b)->next)
	{
		ft_list_push_back(b, (*b)->content, (*b)->index);
		delete_element(0, b, (*b)->next);
	}
	ft_putendl("rr");
	flag->count++;
	if (flag->w)
		print_stack(*a, *b, flag);
}

void	p_rra(t_list **a, t_list *b, t_flags *flag)
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
	ft_putendl("rra");
	flag->count++;
	if (flag->w)
		print_stack(*a, b, flag);
}

void	p_rrb(t_list *a, t_list **b, t_flags *flag)
{
	t_list *last;

	if (*b && (*b)->next)
	{
		last = *b;
		while (last->next->next)
			last = last->next;
		ft_list_push_front(b, last->next->content, last->next->index);
		delete_element(last, &(last->next), 0);
	}
	ft_putendl("rrb");
	flag->count++;
	if (flag->w)
		print_stack(a, *b, flag);
}
