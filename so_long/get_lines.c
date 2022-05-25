/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:37:38 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 14:55:45 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft.h"

int	get_first_line(t_data_map *map, char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
		return (free_and_close(NULL, fd));
	map->width = ft_strlen(*line);
	return (1);
}

int	get_others_lines(char **line, int fd)
{
	char	*temp;

	temp = *line;
	*line = get_next_line(fd);
	free (temp);
	if (!*line)
		return (0);
	return (1);
}
