/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/05/01 17:38:39 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <libft.h>
# include <stdint.h>

# define VECTOR_INITIAL_SIZE	4
# define VECTOR_INCREASE_RATIO	2
# define VECTOR_DECREASE_RATIO	6

typedef struct	s_vector
{
	size_t		elmnt_size;
	size_t		elmnt_count;
	size_t		elmnt_max;
	uint8_t		*data;
	uint8_t		*data_end;
}				t_vec;

int				vec_add(t_vec *vector, void *element);
void			vec_set(t_vec *vector, size_t i, void *element);
void			vec_del(t_vec *vector);
void			*vec_get(t_vec *vector, size_t index);
void			*vec_increase(t_vec *vector, size_t	size);
int				vec_initalize(t_vec *vector, size_t elmnt_size);
int				vec_realloc(t_vec *vec, size_t new_size);
int				vec_rm(t_vec *vector, size_t index);

#endif
