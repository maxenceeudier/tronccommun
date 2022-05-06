/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:35:10 by meudier           #+#    #+#             */
/*   Updated: 2022/05/06 18:09:36 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int ft_lstsize(t_list *lst)
{
    int     i;

    i = 0;

    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

void    ft_sort(int **tab, int size)
{
    int     i;
    int     j;
    int    temp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if ((*tab)[i] - (*tab)[j] > 0)
            {
                temp = (*tab)[i];
                (*tab)[i] = (*tab)[j];
                (*tab)[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int     lst_is_croissant(t_list *lst)
{
    while (lst->next)
    {
        if (lst->data - lst->next->data > 0)
            return (0);
        lst = lst->next;
    }
    return (1);
}

int     lst_is_decroissant(t_list *lst)
{
    while (lst->next)
    {
        if (lst->data - lst->next->data < 0)
            return (0);
        lst = lst->next;
    }
    return (1);
}

t_list *ft_lstlast(t_list *lst)
{
    while (lst->next)
        lst = lst->next;
    return (lst);
}