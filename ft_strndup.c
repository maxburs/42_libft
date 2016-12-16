/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:28:11 by mburson           #+#    #+#             */
/*   Updated: 2016/12/13 20:28:13 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <errno.h>

//todo: add to main lib and set up repo for that

char				*ft_strndup(char *str, size_t n)
{
	char	*new_str;

	if (!(new_str = (char*)malloc(sizeof(char) * (n + 1))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	new_str[n] = '\0';
	while (n)
	{
		n--;
		new_str[n] = str[n];
	}
	return (new_str);
}
