#include <stdlib.h>
#include <stddef.h>
#include "list.h"


t_list  *create_elem(int data)
{
    t_list  *elem;

    elem = (t_list*)malloc(sizeof(t_list *));
    if (!elem)
        return NULL;
    elem->data = data;
    elem->next = NULL;
    return (elem);
}

void    push_back(t_list **lst, int data)
{
    t_list  *last;

    last =  *lst;
    while (last->next)
        last = last->next;
    last->next = create_elem(data);
}

t_list *init_list(int ac, char **av)
{
    int     i;
    t_list  *lst;

    if (ac >1)
    {
        i = 1;
        while (i < ac)
        {
            if (i == 1)
                lst = create_elem(ft_atoi(av[1]));
            else
                push_back(&lst, ft_atoi(av[i]));
            if (!ft_isdigit(av[i]))
                return (NULL);
            i++;
        }
        return (lst);
    }
    return (NULL);
}