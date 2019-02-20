/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 06:53:02 by kcarrot           #+#    #+#             */
/*   Updated: 2018/11/24 18:59:14 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*p;

	i = 0;
	p = begin_list;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}
