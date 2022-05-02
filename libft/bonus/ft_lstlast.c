#include "list.h"

t_list *ft_lstlast(t_list *lst)
{
    while (lst->next)
        lst = lst->next;
    return (lst);
}

/*
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void    ft_listadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    *lst = new;
}

t_list  *ft_lstnew(void *content)
{
    t_list  *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

int main()
{
    t_list *lst = ft_lstnew("salut");
    ft_listadd_front(&lst, ft_lstnew("hey !"));
    ft_listadd_front(&lst, ft_lstnew("ho"));
    t_list *begin = lst;
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
    printf("%s\n", (char *)ft_lstlast(begin)->content);
    return (0);
}*/