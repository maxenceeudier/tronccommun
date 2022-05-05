#include <unistd.h>
#include "list.h"
#include <stdio.h>

int     check(t_list *lst)
{
    while (lst->next)
    {
        if (lst->data > lst->next->data)
            return (0);
        lst = lst->next;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_list  *lsta;
    t_list  *lstb;
    char    **rules;

    lstb = NULL;
    lsta = init_list(ac, av);
    if (!lsta)
    {
        write (2, "Error\n", 6);
        return (0);
    }
    rules = get_rules();
    if (!appli_rules(rules, &lsta, &lstb))
    {
        write (2, "Error\n", 6);
        return (0);
    }
    printf("\n\n");

    t_list *last = lsta;
    while (last)
    {
        printf("%d\n",last->data);
        last = last->next;
    }
    printf("----\n");
    
    t_list *lstbb = lstb;
    while (lstbb)
    {
        printf("%d\n",(lstbb)->data);
        lstbb = (lstbb)->next;
    }
    if (check(lsta) && !lstb)
        write (1, "OK", 2);
    else
        write (1, "KO", 2);
    return (1);
}