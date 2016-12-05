/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:43:31 by mburson           #+#    #+#             */
/*   Updated: 2016/11/30 16:43:39 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

size_t	ft_strlcat(char *restrict s1, const char *restrict s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		if (i < size - 1)
			s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (i);
}
