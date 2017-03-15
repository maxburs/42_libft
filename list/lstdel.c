/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:07:33 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 17:07:35 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void	lstdel(t_list **alst, void (*del)(void *))
{
	if ((*alst)->next)
		lstdel(&((*alst)->next), del);
	lstdelone(alst, del);
}
