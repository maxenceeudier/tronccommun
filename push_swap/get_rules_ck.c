/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules_ck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:40:04 by meudier           #+#    #+#             */
/*   Updated: 2022/05/06 10:49:38 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#define BUFFER_SIZE 4096

char    **get_rules(void)
{
    char    **rules;
    char    buffer[BUFFER_SIZE];
    int     rtr;
    int     i;

    rtr = read (1, buffer, 1);
    i = 0;
    printf("ok, %c", buffer[0]);
    while (rtr > 0 && i < BUFFER_SIZE)
    {
        i++;
        rtr = read (1, buffer + i, 1);
    }
    buffer[i] = 0;
    rules = ft_split(buffer, '\n');
    return (rules);
}