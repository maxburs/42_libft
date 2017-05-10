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

/*
** increases the vector by the specified number of elemnets and then returns
**     a pointer to the new space
*/

void	*vec_increase(t_vec *vector, size_t	size)
{
	void	*new_space;

	if (vector->elmnt_count + size > vector->elmnt_max)
	{
		if (-1 == vec_realloc(vector,
			(vector->elmnt_count + size) * VECTOR_INCREASE_RATIO))
			return (NULL);
	}
	new_space = vector->data_end;
	vector->elmnt_count + size;
	vector->data_end = (uint8_t*)vector->data_end + (vector->elmnt_size * size);
	return (new_space);
}
