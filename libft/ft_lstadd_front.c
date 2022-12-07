/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:22:39 by meudier           #+#    #+#             */
/*   Updated: 2022/05/03 16:23:43 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

t_list  *ft_lstnew(void *content)
{
t_list  *new;

new = (t_list *)malloc(sizeof(t_list));
if (!new)
return (NULL);
new->content = content;
new->next = NULL;
return (new);
}

int main()
{
t_list *lst = ft_lstnew("salut");
ft_lstadd_front(&lst, ft_lstnew("hey !"));
ft_lstadd_front(&lst, ft_lstnew("ho"));
while (lst)
{
printf("%s\n", (char *)lst->content);
lst = lst->next;
}
return (0);
}*/
