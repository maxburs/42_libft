/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:14:05 by mburson           #+#    #+#             */
/*   Updated: 2016/11/30 17:14:07 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	character;
	size_t	i;

	character = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == character)
			return (char*)(s + i);
		i++;
	}
	if (s[i] == character)
		return (char*)(s + i);
	return (NULL);
}
