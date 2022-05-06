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

static void    *get_lst(int ac, char *num, int *index, t_list **lst)
{
    int     i;

    if (ac > 2)
        i = 1;
    else
        i = 0;
    if (*index == i)
        *lst = create_elem(ft_atoi(num));
    else
        push_back(lst, ft_atoi(num));
    if (!ft_isdigit(num))
        return (NULL);
    (*index)++;
    return ("ok");
}

t_list *init_list(int ac, char **av)
{
    int     i;
    t_list  *lst;
    char    **tab_value;

    if (ac > 2)
    {
        i = 1;
        while (i < ac)
            if (!get_lst(ac, av[i], &i, &lst))
                return (NULL);
        return (lst);
    }
    if (ac == 2)
    {
        tab_value = ft_split(av[1], ' ');
        i = 0;
        while (tab_value[i])
        {
            if (!get_lst(ac, tab_value[i], &i, &lst))
                return (NULL);
        }
        return (lst);
    }
    return (NULL);
}