/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:46:56 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdlib.h>
#include <libft.h>

int		vec_add(t_vec *vector, void *element)
{
	if (vector->elmnt_count == vector->elmnt_max)
	{
		if (-1 == vec_realloc(vector,
			vector->elmnt_count * VECTOR_INCREASE_RATIO))
			return (-1);
	}
	vector->elmnt_count++;
	ft_memcpy(vector->data_end, element, vector->elmnt_size);
	vector->data_end = (uint8_t*)vector->data_end + vector->elmnt_size;
	return (0);
}
