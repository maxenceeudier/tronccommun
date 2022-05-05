#include "list.h"
#include <unistd.h>

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

void    pa(t_list **lstb, t_list **lsta)
{
    lst_push(lstb, lsta);
    write (1, "pa\n", 3);
}

void    pb(t_list **lsta, t_list **lstb)
{
    lst_push(lsta, lstb);
    write (1, "pb\n", 3);
}

void    ra(t_list **lsta)
{
    lst_rotate(lsta);
    write (1, "ra\n", 3);
}

void    rb(t_list **lstb)
{
    lst_rotate(lstb);
    write (1, "rb\n", 3);
}

void    rra(t_list **lsta)
{
    lst_rotate_rev(lsta);
    write (1, "rra\n", 4);
}

void    rrb(t_list **lstb)
{
    lst_rotate_rev(lstb);
    write (1, "rrb\n", 4);
}

void    sa(t_list **lsta)
{
    lst_swap(lsta);
    write (1, "sa\n", 3);
}

void    sb(t_list **lstb)
{
    lst_swap(lstb);
    write (1, "sb\n", 3);
}

void    ss(t_list **lsta, t_list **lstb)
{
    lst_swap(lstb);
    lst_swap(lsta);
    write (1, "ss\n", 3);
}