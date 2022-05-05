#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void    get_mid_and_chunck(t_list *lst, int *mid, int *chunk)
{
    int     size;
    int    *temp;
    int     i;
    int     len;

    size = ft_lstsize(lst);
    temp = (int *)malloc(size);
    if (!temp)
        return ;
    i = 0;
    while (lst)
    {
        temp[i] = lst->data;
        lst = lst->next;
        i++;
    }
    ft_sort(&temp, i);
    i = 0;
    *mid = temp[size / 2];
    len = 0;
    while (i < size)
    {
        if (temp[i] < *mid)
            len++;
            i++;
    }
    *chunk += len;
    free(temp);
}

void    get_mid_and_chunck_b(t_list *lst, int *mid, int *chunk)
{
    int     size;
    int    *temp;
    int     i;
    int     len;

    size = ft_lstsize(lst);
    temp = (int *)malloc(size);
    if (!temp)
        return ;
    i = 0;
    while (lst)
    {
        temp[i] = lst->data;
        lst = lst->next;
        i++;
    }
    ft_sort(&temp, i);
    *mid = temp[size / 2];
    i = 0;
    len = 0;
    while (i < size)
    {
        if (temp[i] >= *mid)
            len++;
            i++;
    }
    *chunk += len;
    free(temp);
}