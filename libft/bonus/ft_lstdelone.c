#include <stdlib.h>
#include "list.h"
#include <stdio.h>

/*
void    del(void *data)
{
    data = 0;
}


void    ft_lstdelone(t_list **lst, void (*del)(void *))
{
    t_list  *temp;

    temp = *lst;
    *lst = (*lst)->next;
    (*del)(temp->content);
    free(temp);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;

    if (lst)
    {
        if (!*lst)
            *lst = new;
        else
        {
            last =  *lst;
            while (last->next)
                last = last->next;
            last->next  = new;
        }
    }
}
*/
void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
/*
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
    ft_lstadd_back(&lst, ft_lstnew("hey !"));
    ft_lstadd_back(&lst, ft_lstnew("ho"));
    ft_lstdelone(lst->next, &del);
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
    return (0);
}*/: