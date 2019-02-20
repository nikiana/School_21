/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 06:23:34 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/23 18:23:08 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_push_back(t_list **begin_list, int content, int index)
{
	t_list *tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, index);
		tmp->next->prev = tmp;
		return (tmp->next);
	}
	*begin_list = ft_lstnew(content, index);
	return (*begin_list);
}
