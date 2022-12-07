/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:29:19 by meudier           #+#    #+#             */
/*   Updated: 2022/05/03 16:31:30 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
/*
   int main()
   {
   t_list *lst = ft_lstnew("salut");
   ft_lstadd_back(&lst, ft_lstnew("hey !"));
   ft_lstadd_back(&lst, ft_lstnew("ho"));
   ft_lstdelone(lst->next, &del);
   while (lst)
   {
   printf("%s\n", (char *)lst->content);
   lst = lst->next;
   }
   return (0);
   }*/
