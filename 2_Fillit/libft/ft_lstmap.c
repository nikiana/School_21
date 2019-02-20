/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:52:33 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/29 16:42:20 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *buffer;

	if (lst)
	{
		if (!(buffer = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		buffer = (*f)(buffer);
		buffer->next = ft_lstmap(lst->next, f);
		return (buffer);
	}
	return (NULL);
}
