/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:42:21 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 10:11:37 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


static int     there_is_newline(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        if (str[i++] == '\n')
            return (1);
    return 0;
}

static int    ft_get_line_and_str(char **line, char **str)
{
    int     i;
    int     len;
    char    *temp;

    temp = *str;
    len = 0;
    while ((*str)[len] != '\n' && (*str)[len])
        len++;
    *line = (char *)malloc(len + 2);
    if (!*line)
        return (0);
    i = 0;
    while (i < len && temp[i])
    {
        (*line)[i] = temp[i];
        i++;
    }
    if (len)
        (*line)[i++] = '\n';
    (*line)[i] = 0;
    i = 0;
    while (temp[++len])
        (*str)[i++] = temp[len];
    (*str)[i] = 0;
    return (1);
}

char    *get_next_line(int fd)
{
    char        buffer[BUFFER_SIZE + 1];
    static char *str = NULL;
    char        *temp;
    int         rtr;
    char        *line;

    rtr = BUFFER_SIZE;
    if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
        rtr = -1;
    while (rtr > 0)
    {
        rtr = read(fd , buffer, BUFFER_SIZE);
        if (rtr == - 1)
            break ;
        buffer[rtr] = 0;
        
        temp = str;
        str = ft_strjoin(temp, buffer);
        if (there_is_newline(str))
            break ;
    }
    if (rtr < 0)
        return (NULL);
    if (!ft_get_line_and_str(&line, &str))
    {
        str = NULL;
        return (NULL);
    }
    return (line);
}
/*
int main()
{
    int     fd;
    char    *line1;
    char    *line2;
    char    *line3;

    fd = open("./text", O_RDONLY);
    line1 = get_next_line(1000);
    line2 = get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    // get_next_line2(fd);
    // get_next_line2(fd);
    line3 = get_next_line(fd);
    
    printf("%s%s%s",line1,line2,line3);
    return (0);

}*/