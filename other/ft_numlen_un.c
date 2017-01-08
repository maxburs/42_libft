/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:42:31 by mburson           #+#    #+#             */
/*   Updated: 2016/12/03 13:42:33 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** finds the length needed to represent and undefined number
**		in the given base
*/

int		ft_numlen_un(unsigned long long n, unsigned long long base)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= base;
	}
	return (size);
}
