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

#include <libft.h>
#include <vector.h>
#include <unistd.h>
#include <stdlib.h>

/*
** sets *line to be the next line
** appending to remainder untill a newline is found and then splits at the
**     newline, settting the first half to line and the rest to remainder
*/

# define BUFF_SIZE 128

/*
** return -1 on error, 1 if something was read, and 0 otherwise;
*/

static int		read_through_newline(char **line)
{
	char		buff[BUFF_SIZE + 1];
	ssize_t		size;
	char		*swap;
	int			read_something;

	size = 0;
	read_something = 0;
	while ((0 < (size = read(0, buff, BUFF_SIZE))))
	{
		read_something = 1;
		buff[size] = '\0';
		swap = ft_strjoin(*line, buff);
		free(*line);
		*line = swap;
		if (ft_strchr(buff, '\n'))
			break ;
		if (*line == NULL)
			return (-1);
	}
	if (size == -1)
	{
		free(*line);
		return (-1);
	}
	return (read_something);
}

static int		normalize_remainder(char **remainder)
{
	if (remainder == NULL)
		return (-1);
	if (*remainder == NULL)
	{
		if (NULL == (*remainder = ft_strdup("\0")))
			return (-1);
	}
	return (0);
}

static int		split_line(char **next_line, char **remainder)
{
	char	*line;
	char	*newline;

	line = *remainder;
	if (NULL == (newline = ft_strchr(line, '\n')))
	{
		*next_line = line;
		return (0);
	}
	if (NULL == (*remainder = ft_strdup(newline + 1)))
	{
		free(line);
		return (-1);
	}
	if (NULL == (*next_line = ft_strndup(line, newline - line)))
	{
		free(*remainder);
		free(line);
		return (-1);
	}
	free(line);
	return (1);
}

/*
** on error free's but does not NULL next_line and remainder
**
** reuturns -1 on an error, 1 when there are still lines to be read
**     and 0 otherwise
*/

int				get_next_line(char **next_line, char **remainder)
{
	int		read_something;
	int		newline_found;

	if (-1 == normalize_remainder(remainder)
		|| (NULL == ft_strchr(*remainder, '\n')
			&& -1 == (read_something = read_through_newline(remainder)))
		|| -1 == (newline_found = split_line(next_line, remainder)))
		return (-1);
	return (read_something || newline_found);
}
