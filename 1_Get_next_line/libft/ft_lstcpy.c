/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:23:24 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/05 14:05:57 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *src)
{
	t_list	*new;

	if (!src)
		return (NULL);
	new = ft_lstnew((void const*)(src->content), src->content_size);
	return (new);
}
