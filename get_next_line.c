/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:24:56 by enikole           #+#    #+#             */
/*   Updated: 2019/04/15 22:19:47 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static	t_str		search(t_list **begin, const int fd)
{
	t_list			*ptr;
	t_str			elem;

	ptr = *begin;
	while (ptr != NULL)
	{
		if (ptr->content->fd == fd)
			return (*(ptr->content));
		ptr = ptr->next;
	}
	elem->fd = fd;
	elem->s = ft_strnew(0);
	ft_lstadd(begin, ft_lstnew(&elem, sizeof(elem)));
	return (elem);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*begin;
	t_str			elem;
	size_t			ret;

	if (!line || fd = -1)
		return (-1);
	begin = NULL;
	if (!begin)
	{
		elem->fd = fd;
		elem->s = ft_strnew(0);
		begin = ft_lstnew(&elem, sizeof(elem));
	}
	else
		elem = search(&begin, fd, &elem);
	while (ft_strchr(elem->s, '\n') == NULL)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		// if ret == 0

	}
}
