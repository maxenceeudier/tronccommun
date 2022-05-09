/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:39:42 by meudier           #+#    #+#             */
/*   Updated: 2022/05/09 11:33:34 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int     check(t_list *lst)
{
    if (!lst)
        return (0);
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


    /*t_list *lst_a = lsta;
    while (lst_a)
    {
        printf("%d\n", lst_a->data);
        lst_a = lst_a->next;
    }
    printf("\n-------\n");
    t_list *lst_b = lstb;
    while (lst_b)
    {
        printf("%d\n", lst_b->data);
        lst_b = lst_b->next;
    }*/
    
    if (check(lsta) && !lstb)
        write (1, "OK", 2);
    else
        write (1, "KO", 2);
    return (1);
}