/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:06:38 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/26 16:12:25 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	p_sa(t_list *a, t_list *b, t_flags *flag)
{
	int tmp;

	if (a && a->next)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
		tmp = a->index;
		a->index = a->next->index;
		a->next->index = tmp;
	}
	ft_putendl("sa");
	ft_putendl("sb");
	flag->count++;
	if (flag->w)
		print_stack(a, b, flag);
}

void	p_sb(t_list *a, t_list *b, t_flags *flag)
{
	int tmp;

	if (b && b->next)
	{
		tmp = b->content;
		b->content = b->next->content;
		b->next->content = tmp;
		tmp = b->index;
		b->index = b->next->index;
		b->next->index = tmp;
	}
	ft_putendl("sb");
	flag->count++;
	if (flag->w)
		print_stack(a, b, flag);
}

void	p_ss(t_list *a, t_list *b, t_flags *flag)
{
	int tmp;

	if (a && a->next)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
		tmp = a->index;
		a->index = a->next->index;
		a->next->index = tmp;
	}
	if (b && b->next)
	{
		tmp = b->content;
		b->content = b->next->content;
		b->next->content = tmp;
		tmp = b->index;
		b->index = b->next->index;
		b->next->index = tmp;
	}
	ft_putendl("ss");
	flag->count++;
	if (flag->w)
		print_stack(a, b, flag);
}

void	p_pa(t_list **b, t_list **a, t_flags *flag)
{
	if (*b)
	{
		ft_list_push_front(a, (*b)->content, (*b)->index);
		delete_element(0, b, (*b)->next);
	}
	ft_putendl("pa");
	flag->count++;
	if (flag->w)
		print_stack(*a, *b, flag);
}

void	p_pb(t_list **a, t_list **b, t_flags *flag)
{
	if (*a)
	{
		ft_list_push_front(b, (*a)->content, (*a)->index);
		delete_element(0, a, (*a)->next);
	}
	ft_putendl("pb");
	flag->count++;
	if (flag->w)
		print_stack(*a, *b, flag);
}
