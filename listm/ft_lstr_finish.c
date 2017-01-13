/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:11:38 by mburson           #+#    #+#             */
/*   Updated: 2017/01/13 01:50:27 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <stdlib.h>

static size_t total_length(t_listm *link)
{
	size_t	size;

	size = 0;
	while (link)
	{
		size += ft_strlen(((t_sstr*)link->content)->str);
		link = link->next;
	}
	return (size);
}

char				*ft_lstr_finish(t_listm **start)
{
	t_listm		*link;
	t_listm		*swap;
	char		*str;
	char		*cur;

	if (*start == NULL)
		return (ft_strdup(""));
	if (!(str = (char*)malloc(sizeof(char) * (total_length(*start) + 1))))
		return (NULL);
	cur = str;
	link = *start;
	*start = NULL;
	while (link)
	{
		cur = ft_strplace(cur, ((t_sstr*)link->content)->str);
		cur++;
		if (!((t_sstr*)link->content)->constant)
			free (((t_sstr*)link->content)->str);
		free(link->content);
		swap = link;
		link = link->next;
		free(swap);
	}
	*cur = '\0';
	return (str);
}
