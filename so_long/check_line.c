/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:36:07 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 14:48:31 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft.h"

int	count_num_of_data_map(char c, int *nb_of_one, t_data_map *map)
{
	if (c == '1')
		(*nb_of_one)++;
	else if (c == 'C')
		map->num_of_c++;
	else if (c == 'P')
		map->num_of_p++;
	else if (c == 'E')
		map->num_of_e++;
	else if (c != '0' && c != 'N')
		return (0);
	return (1);
}

int	line_is_ok(char *line, t_data_map *map, int num_of_line)
{
	int	i;
	int	nb_of_one;

	if (!line || line[0] != '1' || map->width != (int)ft_strlen(line)
		|| line[map->width - 1] != '1')
		return (0);
	i = 0;
	nb_of_one = 0;
	while (line[i])
	{
		if (!count_num_of_data_map(line[i], &nb_of_one, map))
			return (0);
		i++;
	}
	if (nb_of_one == map->width && map->first)
		map->first = 0;
	else if (nb_of_one == map->width && !map->first)
		map->last = num_of_line;
	return (1);
}
