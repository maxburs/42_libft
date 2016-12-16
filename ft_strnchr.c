/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:14:05 by mburson           #+#    #+#             */
/*   Updated: 2016/12/15 17:10:50 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_stnrchr(const char *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s != (char)c)
		s++;
	if (s[i] == (char)c)
		return ((char*)&(s[i]));
	return (NULL);
}
