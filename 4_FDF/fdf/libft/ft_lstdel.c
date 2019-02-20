/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:24:43 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/24 20:07:20 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *p;

	if (del && alst)
	{
		while (*alst)
		{
			p = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = p;
		}
		*alst = NULL;
	}
}
