/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 06:42:13 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/24 19:44:15 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list,
		void const *content, size_t content_size)
{
	t_list *tmp;

	if (*begin_list)
	{
		tmp = ft_lstnew(content, content_size);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_lstnew(content, content_size);
}
