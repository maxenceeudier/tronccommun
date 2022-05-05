#include "list.h"
#include <stdio.h>


void    ft_qsort_a(t_list **lsta, t_list **lstb)
{
    int     mid;
    int     chunk;

    mid = 0;
    chunk = 0;
    while (ft_lstsize(*lsta) > 2 && !lst_is_croissant(*lsta))
    {
        get_mid_and_chunck(*lsta, &mid, &chunk);
        while (ft_lstsize(*lstb) != chunk)
        {
            if ((*lsta)->data < mid)
                pb(lsta, lstb);
            else
            {
                if (ft_lstlast(*lsta)->data < mid)
                {
                    rra(lsta);
                    pb(lsta, lstb);
                }
                if (!lst_is_croissant(*lsta))
                    ra(lsta);
            }
            if (ft_lstsize(*lstb) >= 2 && (*lstb)->data < (*lstb)->next->data && (*lsta)->data < (*lsta)->next->data)
                sb(lstb);
            else if ((*lsta)->data > (*lsta)->next->data && *lstb && (*lstb)->data < (*lstb)->next->data)
                ss(lsta,lstb);
        }
    }
    if (!lst_is_croissant(*lsta))
        sa(lsta);
}

void    ft_qsort_b(t_list **lsta, t_list **lstb)
{
    int     mid;
    int     chunk;
    int     i;

    mid = 0;
    chunk = 0;
    while (ft_lstsize(*lstb) > 2 && !lst_is_decroissant(*lstb))
    {
        get_mid_and_chunck_b(*lstb, &mid, &chunk);
        while (ft_lstsize(*lsta) != chunk)
        {
            if ((*lstb)->data >= mid)
                pa(lstb, lsta);
            else
            {
                if (ft_lstlast(*lstb)->data >= mid)
                {
                    rrb(lstb);
                    pa(lstb, lsta);
                }
                if (!lst_is_decroissant(*lstb))
                    rb(lstb);
            }
            if (ft_lstsize(*lstb) >= 2 && (*lsta)->data > (*lsta)->next->data && (*lstb)->data > (*lstb)->next->data)
                sa(lsta);
            else if (ft_lstsize(*lstb) >= 2 && (*lstb)->data < (*lstb)->next->data && (*lsta)->data > (*lsta)->next->data)
                ss(lsta,lstb);
        }
        
    }
    if (!lst_is_decroissant(*lstb))
        sb(lstb);
    i = ft_lstsize(*lstb);
    while (i > 0)
    {
        pa(lstb, lsta);
        i--;
    }
    
}

int main(int ac, char **av)
{
    t_list  *lsta;
    t_list  *lstb;

    lstb = NULL;
    lsta = init_list(ac, av);
    if (!lsta)
    {
        write (2, "Error\n", 6);
        return (0);
    }
    int i = 0;
    while (!(lst_is_croissant(lsta) && !lstb))
    {
        ft_qsort_a(&lsta, &lstb);
        ft_qsort_b(&lsta, &lstb);   
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

  
}