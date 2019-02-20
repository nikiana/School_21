/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 06:42:13 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/23 18:23:16 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, int content, int index)
{
	if (*begin_list)
	{
		(*begin_list)->prev = ft_lstnew(content, index);
		(*begin_list)->prev->next = *begin_list;
		*begin_list = (*begin_list)->prev;
	}
	else
		*begin_list = ft_lstnew(content, index);
}
