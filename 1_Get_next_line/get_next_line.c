/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:42:04 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/05 14:46:54 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		reading(t_list **head, int fd, char **str, char *buf)
{
	int		i;
	char	*tmp;

	if ((i = read(fd, buf, BUFF_SIZE)) == -1)
		return (i);
	if (!i)
	{
		if (*head && (*head)->content && (((char*)((*head)->content))[0])
		&& (i = -2))
			*str = ft_strdup((const char *)(*head)->content);
		else
			*str = 0;
		if (*head)
		{
			free((*head)->content);
			(*head)->content = NULL;
		}
		return (i);
	}
	tmp = (*head)->content;
	(*head)->content = tmp ? ft_strjoin(tmp, buf) : ft_strdup(buf);
	free(tmp);
	ft_bzero(buf, i + 1);
	return (i);
}

int		create_list(t_list **head, int fd, char **str)
{
	char	*tmp;
	t_list	*p;
	char	buf[BUFF_SIZE + 1];
	int		i;

	ft_bzero(buf, BUFF_SIZE + 1);
	p = *head;
	while ((i = 2) && p && p->content_size != (size_t)fd)
		p = p->next;
	if (!p)
		p = ft_list_push_back(head, 0, 0);
	p->content_size = fd;
	while ((!(p->content) || !ft_strchr((const char*)(p->content), '\n'))
	&& i > 0)
		i = reading(&p, fd, str, buf);
	if (i <= 0)
		return (i == -2) ? 1 : i;
	i = 0;
	while (((char*)(p->content))[i] && ((char*)(p->content))[i] != '\n')
		i++;
	*str = ft_strsub((const char*)(p->content), 0, i);
	tmp = ft_strsub((char const*)(p->content), i + 1,
	ft_strlen(&((char*)(p->content))[i]));
	free(p->content);
	return (p->content = tmp) ? 1 : 1;
}

int		check_fd(t_list *head, int fd, char **str)
{
	t_list	*p;
	char	*tmp;
	size_t	i;

	p = head;
	while (p && p->content_size != (size_t)fd)
		p = p->next;
	if (!p || !(p->content))
		return (0);
	i = 0;
	while (((char*)(p->content))[i] != '\n' && ((char*)(p->content))[i])
		i++;
	if (((char*)(p->content))[i] == '\n')
	{
		*str = ft_strnew(i);
		*str = ft_strncpy(*str, (const char*)(p->content), i);
		tmp = ft_strsub((char const*)(p->content), i + 1,
		ft_strlen(&((char*)(p->content))[i + 1]));
		free(p->content);
		p->content = tmp;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	char			*str;
	int				i;

	if (BUFF_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (!(check_fd(head, fd, &str)))
	{
		i = create_list(&head, fd, &str);
		if (i == -1)
			return (-1);
	}
	*line = str;
	return (*line) ? 1 : 0;
}
