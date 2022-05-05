#include "list.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;

    last =  *lst;
    while (last->next)
        last = last->next;
    last->next  = new;
}

void    lst_push(t_list **lst1, t_list **lst2)
{
    t_list  *temp;

    temp = *lst1;
    if (!*lst2)
    {
        *lst2 = *lst1;
        *lst1 = (*lst1)->next;
        (*lst2)->next = NULL;
    }
    else if (*lst1)
    {
        *lst1 = (*lst1)->next;
        temp->next = (*lst2);
        *lst2 = temp;
    }
}

void    lst_swap(t_list **lst)
{
    t_list  *temp;

    if (*lst)
    {
        temp = *lst;
        *lst = (*lst)->next;
        temp->next = temp->next->next;
        (*lst)->next = temp;
    }
}

void    lst_rotate(t_list **lst)
{
    t_list  *temp;

    if (*lst && (*lst)->next)
    {
        temp = *lst;
        *lst = (*lst)->next;
        temp->next = NULL;
        ft_lstadd_back(lst, temp);
    }
}

void    lst_rotate_rev(t_list **lst)
{
    t_list  *last;

    if (*lst && (*lst)->next)
    {
        last = *lst;
        while (last->next->next)
            last = last->next;
        last->next->next = *lst;
        *lst = last->next;
        last->next = NULL;
    }
}

int    ft_lst_swap(char *rule, t_list **lsta, t_list **lstb)
{
    if (rule[1] == 'a' && !rule[2])
        lst_swap(lsta);
    else if (rule[1] == 'b' && !rule[2])
        lst_swap(lstb);
    else if (rule[1] == 's' && !rule[2])
    {
        lst_swap(lstb);
        lst_swap(lsta);
    }
    else
        return (0);
    return (1);
}

int    ft_lst_rotate(char *rule, t_list **lsta, t_list **lstb)
{
    if (rule[1] == 'a' && !rule[2])
        lst_rotate(lsta);
    else if (rule[1] == 'b' && !rule[2])
        lst_rotate(lstb);
    else if (rule[1] == 'r' && !rule[2])
    {
        lst_rotate(lstb);
        lst_rotate(lsta);
    }
    else if (rule[1] == 'r' && rule[2] && !rule[3])
    {
        if (rule[2] == 'a')
            lst_rotate_rev(lsta);
        else if (rule[2] == 'b')
            lst_rotate_rev(lstb);
        else if (rule[2] == 'r')
        {
            lst_rotate_rev(lstb);
            lst_rotate_rev(lsta);
        }
        else
            return (0);
    }
    else
        return (0);
    return (1);
}

int     ft_lst_push(char *rule, t_list **lsta, t_list **lstb)
{
    if (rule[1] == 'a' && !rule[2])
        lst_push(lstb, lsta);
    else if (rule[1] == 'b' && !rule[2])
        lst_push(lsta, lstb);
    else
        return (0);
    return (1);
}

int     appli_rules(char **rules, t_list **lsta, t_list **lstb)
{
    int     i;

    i = 0;
    while (rules[i])
    {
        if (rules[i][0] == 's')
            if (!ft_lst_swap(rules[i], lsta, lstb))
                return (0);
        if (rules[i][0] == 'r')
            if (!ft_lst_rotate(rules[i], lsta, lstb))
                return (0);
        if (rules[i][0] == 'p')
            if (!ft_lst_push(rules[i], lsta, lstb))
                return (0);
        if (rules[i][0] != 'p' && rules[i][0] != 'r'
            && rules[i][0] != 's')
            return (0);
        i++;
    }
    return (1);
}