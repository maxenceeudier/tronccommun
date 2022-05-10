#include "list.h"

static void    get_tab(t_list *lst, int **tab)
{
    int     size;
    int     i;

    size = ft_lstsize(lst);
    *tab = (int *)malloc(size * sizeof(int));
    if (!*tab)
        return ;
    i = 0;
    while (lst)
    {
        (*tab)[i] = lst->data;
        lst = lst->next;
        i++;
    }
    ft_sort(tab, i);
}

static int   the_smallest_exist(t_list *lst, int x)
{
    while (lst)
    {
        if (lst->data == x)
            return (1);
        lst = lst->next;
    }
    return (0);
}

static int     fast_way_to_smaller(t_list *lst, int x)
{
    int     count1;
    int     count2;

    count1 = 0;
    count2 = 0;
    while (lst)
    {
        if (lst->data != x)
            count1++;
        else
            break ;
        lst = lst->next;
    }
    while (lst)
    {
        if (!the_smallest_exist(lst, x))
            count2++;
        lst = lst->next;
    }
    if (count1 <= count2)
        return (count1);
    else
        return (-1 * (count2 + 1));
}



void      sort_short(t_list **lsta, t_list **lstb)
{
    int     *tab;
    int     size;
    int     i;
    int     k;

    get_tab(*lsta, &tab);
    size = ft_lstsize(*lsta);
    i = 0;
    while (i < size && !lst_is_croissant(*lsta))
    {
        while (the_smallest_exist(*lsta, tab[i]) && !lst_is_croissant(*lsta))
        {
            if ((*lsta)->data == tab[i])
                pb (lsta, lstb);
            else
            {
                k = fast_way_to_smaller(*lsta, tab[i]);
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
    if (*lstb)
    {
        size = ft_lstsize(*lstb);
        i = 0;
        while (i < size)
        {
           pa(lstb, lsta);
          i++;
        }
    }
    
}