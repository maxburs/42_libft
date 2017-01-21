/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf_16_32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:59:08 by mburson           #+#    #+#             */
/*   Updated: 2017/01/19 20:59:12 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <libft.h>

#include <stdio.h>

wint_t    ft_utf_16_32(wchar_t **c)
{
	wint_t	res;
	printf("status: %d\n", !(**c & (0b1 << 15)));
	if (!(**c & (0b1 << 15)))
		return ((wint_t)**c);
	printf("working!!\n");
	res = (wint_t)(**c & 0x7FF) << 10;
	printf("status: %x\n", res);
	(*c)++;
	res = res | (wint_t)(**c & 0x3FF);
	return (res);
}
