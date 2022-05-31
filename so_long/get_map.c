/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:23:49 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 12:56:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "ft.h"
#define BUFFER_SIZE 10000

int	free_and_close(char *line, int fd)
{
	if (line)
		free(line);
	if (fd >= 0)
		close (fd);
	return (0);
}

int	get_data(t_data_map *map, char **line, int fd, int *i)
{
	while (*line)
	{
		if (line_is_first(*line))
		{
			if (!get_first_line(map, line, fd))
				return (0);
		}
		else
			if (!get_others_lines(line, fd))
				break ;
		if (!line_is_ok(*line, map, *i))
			return (0);
		(*i)++;
	}
	return (1);
}

int	get_data_map(char **av, t_data_map *map)
{
	int		i;
	char	*line;
	int		fd;

	fd = init_map(map, &i, &line, av[1]);
	if (fd == -1 || !get_data(map, &line, fd, &i))
		return (free_and_close(line, fd));
	if (map->last != i - 1 || map->first != 0)
	{
		ft_printf("Error\nthe border of the map is not close\n");
		return (free_and_close(line, fd));
	}
	if (map->num_of_c < 1
		|| map->num_of_e < 1 || map->num_of_p != 1)
	{
		ft_printf("Error\nIt's missing a 'P', a 'C' or a 'E' in the map\n");
		return (free_and_close(line, fd));
	}
	map->heigth = i;
	free_and_close(line, fd);
	return (1);
}

void	init_vars_map(t_vars *vars, t_data_map map)
{
	vars->map.num_col = map.width;
	vars->map.num_row = map.heigth;
	vars->map.num_of_c = map.num_of_c;
}

int	get_map(t_vars *vars, int ac, char **av)
{
	int			fd;
	int			rtr;
	t_data_map	map;
	char		buffer[BUFFER_SIZE];

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || !is_good_extension(av[1]) || fd == -1
		|| !get_data_map(av, &map))
	{
		if (ac != 2)
			ft_printf("Error\nThe number of arg must be 2\n");
		else
			ft_printf("Error\nImpossible to open the file\n");
		return (free_and_close(NULL, fd));
	}	
	rtr = read(fd, buffer, BUFFER_SIZE);
	if (rtr == -1)
		return (free_and_close(NULL, fd));
	buffer[rtr] = 0;
	vars->map.map = ft_split(buffer, '\n');
	if (!vars->map.map)
		return (free_and_close(NULL, fd));
	init_vars_map(vars, map);
	close(fd);
	return (1);
}
