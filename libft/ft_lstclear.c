/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:32:09 by meudier           #+#    #+#             */
/*   Updated: 2022/05/03 16:32:35 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void    del(void *data)
// {
//     data = NULL;
// }
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		(*del)(temp->content);
		free(temp);
	}
}

// #include <stdlib.h>
// #include <stdio.h>

// void    ft_lstadd_back(t_list **lst, t_list *new)
// {
//     t_list  *last;

//     last =  *lst;
//     while (last->next)
//         last = last->next;
//     last->next  = new;
// }

// t_list  *ft_lstnew(void *content)
// {
//     t_list  *new;

//     new = (t_list *)malloc(sizeof(t_list));
//     if (!new)
//         return (NULL);
//     new->content = content;
//     new->next = NULL;
//     return (new);
// }

// int main()
// {
//     t_list  *lst = ft_lstnew("salut");

//     ft_lstadd_back(&lst, ft_lstnew("hey !"));
//     ft_lstadd_back(&lst, ft_lstnew("ho"));
//     ft_lstadd_back(&lst, ft_lstnew("a"));
//     ft_lstadd_back(&lst, ft_lstnew("b"));
//     ft_lstadd_back(&lst, ft_lstnew("c"));
//     ft_lstclear(&lst->next->next->next, &del);

//     while (lst)
//     {
//         printf("%s\n", (char *)lst->content);
//         lst = lst->next;
//     }
//     return (0);
// }
