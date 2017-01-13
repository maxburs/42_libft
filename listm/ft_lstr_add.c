/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstr_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:50:17 by mburson           #+#    #+#             */
/*   Updated: 2017/01/13 01:50:18 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		ft_lstr_add(t_listm **start, char *str, _Bool constant)
{
	t_sstr	*s;

	if (!(s = (t_sstr*)malloc(sizeof(t_sstr))))
		return ;
	s->str = str;
	s->constant = constant;
	ft_lstmadd_b(start, s);
}
