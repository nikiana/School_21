/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:52:54 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/12/04 16:01:48 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *cur;

	cur = *alst;
	if (cur)
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	else
		*alst = new;
}
