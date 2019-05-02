/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:33:24 by enikole           #+#    #+#             */
/*   Updated: 2019/04/11 14:53:05 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	l1;
	size_t	i;

	i = 0;
	l1 = ft_strlen(s1);
	while (s2[i] != '\0' && i < n)
	{
		s1[l1 + i] = s2[i];
		i++;
	}
	s1[l1 + i] = '\0';
	return (s1);
}
