/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:38:58 by meudier           #+#    #+#             */
/*   Updated: 2022/05/09 15:55:55 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void    ft_qsort_a(t_list **lsta, t_list **lstb)
{
    int     mid;
    int     chunk;

    mid = 0;
    chunk = 0;
    while (ft_lstsize(*lsta) > 2 && !lst_is_croissant(*lsta))
    {
        get_mid_and_chunck(*lsta, &mid, &chunk);
        while (ft_lstsize(*lstb) != chunk && ft_lstsize(*lsta) > 2  && !lst_is_croissant(*lsta))
        {
            if ((*lsta)->data < mid)
            {
                pb(lsta, lstb);
                if ((*lstb)->next && (*lstb)->data > (*lstb)->next->data)
                    sb(lstb);
            }
            else
            {
                if (ft_lstlast(*lsta)->data < mid)
                {
                    rra(lsta);
                    pb(lsta, lstb);
                    if ((*lstb)->next && (*lstb)->data > (*lstb)->next->data)
                        sb(lstb);
                }
                if (!lst_is_croissant(*lsta))
                    ra(lsta);
            }
            /*if (ft_lstsize(*lstb) >= 2 && (*lstb)->data < (*lstb)->next->data && (*lsta)->data < (*lsta)->next->data)
                sb(lstb);
            else if (ft_lstsize(*lstb) >= 2 && (*lsta)->data > (*lsta)->next->data && (*lstb)->data > (*lstb)->next->data)
                sa(lsta);
            else if ((*lsta)->data > (*lsta)->next->data && *lstb && (*lstb)->next && (*lstb)->data < (*lstb)->next->data)
                ss(lsta,lstb);*/
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
    chunk = ft_lstsize(*lsta);
    while ((ft_lstsize(*lstb) > 2 && !lst_is_decroissant(*lstb)))
    {
        get_mid_and_chunck_b(*lstb, &mid, &chunk);
        while (ft_lstsize(*lsta) != chunk && ft_lstsize(*lstb) > 2 && !lst_is_decroissant(*lstb))
        {
            if ((*lstb)->data >= mid && !lst_is_croissant(*lsta))
            {
                pa(lstb, lsta);
                if ((*lsta)->data > (*lsta)->next->data)
                    sa(lsta);
            }
            else
            {
                if (ft_lstlast(*lstb)->data >= mid)
                {
                    rrb(lstb);
                    pa(lstb, lsta);
                    if ((*lsta)->data > (*lsta)->next->data)
                        sa(lsta);
                }
                if (!lst_is_decroissant(*lstb))
                    rb(lstb);
            }
            /*if (ft_lstsize(*lstb) >= 2 && (*lsta)->data > (*lsta)->next->data && (*lstb)->data > (*lstb)->next->data)
                sa(lsta);
            else if (ft_lstsize(*lstb) >= 2 && (*lstb)->data < (*lstb)->next->data && (*lsta)->data < (*lsta)->next->data)
                sb(lstb);
            else if (ft_lstsize(*lstb) >= 2 && (*lstb)->data < (*lstb)->next->data && (*lsta)->data > (*lsta)->next->data)
                ss(lsta,lstb);*/
        }
    }
    if (!lst_is_decroissant(*lstb))
        sb(lstb);
    i = ft_lstsize(*lstb);
    while (i > 0)
    {
        pa(lstb, lsta);
        /*if ((*lsta)->data > (*lsta)->next->data)
            sa(lsta);*/
        i--;
    }
    
}