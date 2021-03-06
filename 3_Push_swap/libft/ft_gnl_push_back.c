/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 06:23:34 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/04 23:28:43 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_gnl_push_back(t_gnl **begin_list,
		void const *content, size_t content_size)
{
	t_gnl *tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_gnlnew(content, content_size);
		return (tmp->next);
	}
	*begin_list = ft_gnlnew(content, content_size);
	return (*begin_list);
}
