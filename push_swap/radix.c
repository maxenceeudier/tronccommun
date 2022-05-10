#include "list.h"

int     is_all_zero(t_list *lst, int j)
{
    while (lst)
    {
        if ((lst->data % (10 * j)) / j != 0)
            return (0);
        lst = lst->next;
    }
    return (1);
}

int     equal_to_i_exist(t_list *lst, int i, int j)
{
    int     count;

    count = 0;
    while (lst)
    {
        if ((lst->data % (10 * j)) / j == i)
            count++;            
        lst = lst->next;
    }
    return (count);
}

int     is_the_smallest(t_list *lst, int i, int j, int data)
{
    while (lst)
    {
        if ((lst->data % (10 * j)) / j == i)
            if (lst->data % (10 * j) < data % (10 * j))
                return (0);
        lst = lst->next;
    }
    return (1);
}

int     is_the_bigger(t_list *lst, int i, int j, int data)
{
    while (lst)
    {
        if ((lst->data % (10 * j)) / j == i)
            if (lst->data % (10 * j) > data % (10 * j))
                return (0);
        lst = lst->next;
    }
    return (1);
}

int     fast_way_to_smallest(t_list *lst, int i, int j)
{
    int     count;
    int     other_way;
    int     len;

    count = 0;
    len = ft_lstsize(lst);
    while (lst && !is_the_smallest(lst, i, j, lst->data))
    {
        count++;
        lst = lst->next;
    }
    other_way = len - count;  
    if (count <= other_way)
        return (count);
    else
        return (-1 * (other_way));
}

int     fast_way_to_bigger(t_list *lst, int i, int j)
{
    int     count;
    int     other_way;
    int     len;

    count = 0;
    len = ft_lstsize(lst);
    while (lst && !is_the_bigger(lst, i, j, lst->data))
    {
        count++;
        lst = lst->next;
    }
    other_way = len - count;  
    if (count <= other_way)
        return (count);
    else
        return (-1 * (other_way));
}


void    radix_a(t_list **lsta, t_list **lstb, int j)
{
    int     i;
    int     k;

    i = 0;
    while (i <= 9 && !lst_is_croissant(*lsta))
    {
        while (equal_to_i_exist(*lsta, i, j) && !lst_is_croissant(*lsta))
        {
            if (is_the_smallest(*lsta, i, j, (*lsta)->data))
                pb (lsta, lstb); 
            else
            {
                k = fast_way_to_smallest(*lsta, i, j);
                if (k >= 0)
                {
                    while (k > 0)
                    {
                        ra(lsta);
                        k--;
                    }
                }
                else
                {
                    while (k < 0)
                    {
                        rra(lsta);
                        k++;
                    }
                }
            }
        }
        i++;
    }
    if (!lst_is_croissant(*lsta))
            sa(lsta);
}

void    radix_b(t_list **lsta, t_list **lstb, int j)
{
    int     i;
    int     k;

    i = 0;
    while (i <= 9 && *lstb && !lst_is_decroissant(*lstb))
    {
        while (equal_to_i_exist(*lstb, i, j) && *lstb && !(lst_is_decroissant(*lstb)))
        {
            if (is_the_bigger(*lstb, i, j, (*lstb)->data))
                pa(lstb, lsta);
            else
            {
                k = fast_way_to_bigger(*lstb, i, j);
                if (k >= 0)
                {
                    while (k > 0)
                    {
                        rb(lstb);
                        k--;
                    }
                }
                else
                {
                    while (k < 0)
                    {
                        rrb(lstb);
                        k++;
                    }
                }
            }     
        }
        i++;
    }
    i = ft_lstsize(*lstb);
    if (*lstb && lst_is_decroissant(*lstb))
    {
        while (i >= 0)
        {
            pa(lstb, lsta);
            i--;
        }
    }
}