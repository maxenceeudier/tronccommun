/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:34:10 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 14:19:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//void    del(void *data)
// {
//     data = 0;
// }
//
// #include <stdio.h>
//
// void    *f(void *data)
// {
//     char *new;
//     int     i = 0;
//     while (((char*)data)[i])
//         i++;
//     new = malloc(i + 2);
//     if (!new)
//         return (NULL);
//     i = 0;
//     while (((char*)data)[i])
//     {
//         new[i] = ((char*)data)[i];
//         i++;
//     } 
//     new[i] = 'X';
//     new[i + 1] = 0;
//     return ((void *)new);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rslt;
	t_list	*new;
	t_list	*begin;

	begin = lst;
	if (!f || !del || !lst)
		return (NULL);
	rslt = ft_lstnew((*f)(lst->content));
	if (!rslt)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&begin, &free);
			return (NULL);
		}
		ft_lstadd_back(&rslt, new);
		lst = lst->next;
	}
	return (rslt);
}

// #include <stdio.h>

// int main()
// {
//     t_list  *lst = ft_lstnew("salut");
//     t_list  *rslt;

//     ft_lstadd_back(&lst, ft_lstnew("hey !"));
//     ft_lstadd_back(&lst, ft_lstnew("ho"));

//     rslt = ft_lstmap(lst, &f, &del);

//     while (rslt)
//     {
//         printf("%s\n", (char *)rslt->content);
//         rslt = rslt->next;
//     }
//     return (0);
// }
