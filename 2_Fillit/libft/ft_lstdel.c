/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:40:03 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/11/26 12:45:08 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *clearedlist;

	while (*alst)
	{
		clearedlist = *alst;
		(*del)((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(clearedlist);
	}
}
