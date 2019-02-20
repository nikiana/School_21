/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:07:15 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/27 20:27:00 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_lst(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *res;
	t_list *tmp;

	if (!f || !lst)
		return (NULL);
	if (!(new = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
		return (NULL);
	res = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
			return (free_lst(&new));
		new->next = tmp;
		new = tmp;
		lst = lst->next;
	}
	return (res);
}
