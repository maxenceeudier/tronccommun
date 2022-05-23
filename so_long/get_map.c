/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:23:49 by meudier           #+#    #+#             */
/*   Updated: 2022/05/23 18:40:13 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft.h"
#define BUFFER_SIZE 10000

int extension_is_good(char *str)
{
    char    *ext;
    int     i;

    i = 0;
    ext = ".ber";
    while (str[i] == ext[i])
    {
        if (ext[i] == 0)
            return (1);
        i++;
    }
    return (0);
}

int is_good_extension(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (extension_is_good(str + i))
            return (1);
        i++;
    }
    return (0);
}

int    count_num_of_data_map(char c, int *nb_of_one, t_data_map *map)
{
    if (c == '1')
        (*nb_of_one)++;
    else if (c == 'C')
        map->num_of_c++;
    else if (c == 'P')
        map->num_of_p++;
    else if (c == 'E')
        map->num_of_e++;
    else if (c != '0')
        return (0);
    return (1);
}

int line_is_ok(char *line, t_data_map *map, int num_of_line)
{
    int i;
    int nb_of_one;

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

int    init_map(t_data_map *map, int *i, char** line, char *file)
{
    int fd;

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

int free_and_close(char *line, int fd)
{
    if (line)
        free(line);
    close (fd);
    return (0);
}

int get_first_line(t_data_map *map, char **line, int fd)
{
    *line = get_next_line(fd);
    if (!*line)
        return (free_and_close(NULL, fd));
    map->width = ft_strlen(*line);
    return (1);
}

int get_others_lines(char **line, int fd)
{
    char    *temp;

    temp = *line;
    *line = get_next_line(fd);
    free (temp);
    if (!*line)
        return (0);
    return (1);
}

int line_is_first(char *str)
{
    int     i;
    char    *first;

    i = 0;
    first = "first";
    while (str[i] == first[i])
    {
        if (str[i] == 0)
            return (1);
        i++;
    }
    return (0);
}

int    get_data(t_data_map *map, char **line, int fd, int *i)
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
            return (free_and_close(*line, fd));
        (*i)++;
    }
    return (1);
}

int get_data_map(char **av, t_data_map *map)
{
    int         i;
    char        *line;
    int         fd;

    fd =  init_map(map, &i, &line, av[1]);
    if (!get_data(map, &line, fd, &i))
        return (0);
    if (map->last != i - 1 || map->first != 0 || map->num_of_c < 1
        || map->num_of_e < 1 || map->num_of_p != 1)
        return (free_and_close(line, fd));      
    map->heigth = i;
    free_and_close(line, fd);
    return (1);
}

int    get_map(t_vars *vars, int ac, char **av)
{
    int         fd;
    int         rtr;
    t_data_map  map;
    char        buffer[BUFFER_SIZE];

    if (!get_data_map(av, &map))
        return (0);
    fd = open(av[1], O_RDONLY);
    if (ac != 2 || !is_good_extension(av[1]) || !fd )
        return (free_and_close(NULL, fd));
    rtr = read(fd, buffer, BUFFER_SIZE);
    if (rtr == -1)
        return (0);
    buffer[rtr] = 0;
    vars->map.map = ft_split(buffer, '\n');
    if (!vars->map.map)
        return (0);
    vars->map.num_col = map.width;
	vars->map.num_row = map.heigth;
    return (1);
}
/*    
#include <stdio.h> 
int main (int ac, char **av)
{
    int i;
    t_vars vars;

    i = 0;
    if (!get_map(&vars, ac, av))
        write (2, "error\n", 6);
    while ((vars.map.map)[i])
        printf("%s\n", (vars.map.map)[i++]);
}*/