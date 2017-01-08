/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:27:27 by mburson           #+#    #+#             */
/*   Updated: 2017/01/07 20:27:29 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

unsigned long long int	ft_absolute(long long int n)
{
	if (n < 0)
		n = 0 - (n ^ 0x8000000000000000) - (LLONG_MIN);
	return ((unsigned long long int)n);
}
