/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:32:12 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 15:02:01 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft.h"

int	init_map(t_data_map *map, int *i, char **line, char *file)
{
	int	fd;

	fd = open (file, O_RDONLY);
	*i = 0;
	*line = "first";
	map->last = 0;
	map->first = 1;
	map->num_of_c = 0;
	map->num_of_p = 0;
	map->num_of_e = 0;
	map->width = 0;
	map->heigth = 0;
	return (fd);
}
