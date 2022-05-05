#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#define BUFFER_SIZE 4096


int     get_buffer_size(void)
{
    int     len;
    char    buff[1];

    len = 0;
    while (read (1, buff, 1))
        len ++;
    return (len);
}

char    **get_rules(void)
{
    char    **rules;
    char    buffer[BUFFER_SIZE];
    int     rtr;
    int     i;

    rtr = read (1, buffer, 1);
    i = 0;
    while (rtr && i < BUFFER_SIZE)
    {
        i++;
        rtr = read (1, buffer + i, 1);
    }
    buffer[i] = 0;
    rules = ft_split(buffer, '\n');
    return (rules);
}