/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:53:20 by enikole           #+#    #+#             */
/*   Updated: 2019/04/15 19:24:08 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static	ssize_t		search(char *buf)
{
	ssize_t			i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] = '\n')
			return (i);
		i++;
	}
	return (-1);
}

static	t_str		*create_elem(const int fd)
{
	t_str			*elem;

	if ((elem = (t_str*)malloc(sizeof(t_str))) != NULL)
	{
		elem->fd = fd;
		elem->s = ft_strnew(BUF_SIZE);
	}
	return (elem);
}

static	t_str		*ft_list(static t_list *begin, const int fd)
{
	t_list			*ptr;
	t_str			*elem;

	if (!begin)
		if ((elem = create_elem(fd)) != NULL)
		{
			begin = ft_lstnew(elem, sizeof(*elem));

		}
	else
	{
		elem = NULL;
		ptr = begin;
		while (ptr->next != NULL)
		{
			if (ptr->content->fd != fd)
			{
				elem = ptr->content;
				if ((i = search(elem->s)) != -1)
				{
				}
			}
		}
	}
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*begin;
	t_list			*ptr;
	t_str			*elem;
	char			*buf[BUF_SIZE + 1];
	size_t			ret;
	ssize_t			i;

	begin = NULL;
	ft_list(begin, fd);










	if (!begin)
	{
		elem = (t_str*)malloc(sizeof(t_str));
		elem->fd = fd;
		elem->s = ft_strnew(BUF_SIZE);
		begin = ft_lstnew(elem, sizeof(*elem));
	}
	else
	{
		elem = NULL;
		ptr = begin;
		while (ptr->next != NULL)
		{
			if (ptr->content->fd != fd)
			{
				elem = ptr->content;
				if ((i = search(elem->s)) != -1)
				{
					buf = elem->s;
					ft_strncpy(elem->s, &(buf[i + 1]), ret - i);
					buf[i] = '\0';
					*line = ft_strjoin(*line, buf);
					return (1); //return value - ?
				}
				break ;
			}
			ptr = ptr->next;
		}
		if (!elem)
		{
			elem = (t_str*)malloc(sizeof(t_str));
			elem->fd = fd;
			elem->s = ft_strnew(BUF_SIZE);
			ft_lstadd(ptr, ft_lstnew(elem, sizeof(*elem)));
		}
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if ((i = search(buf)) != -1)
		{
			ft_strncpy(elem->s, &(buf[i + 1]), ret - i);
			buf[i] = '\0';
			break ;
		}
		*line = ft_strjoin(*line, buf); // free step above
	}
	*line = ft_strjoin(*line, buf);
	return (1); //return value - ?
}
