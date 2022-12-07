/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:20:33 by meudier           #+#    #+#             */
/*   Updated: 2022/05/03 16:22:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			last = *lst;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

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
ft_lstadd_back(&lst, ft_lstnew("hey !"));
ft_lstadd_back(&lst, ft_lstnew("ho"));
while (lst)
{
printf("%s\n", (char *)lst->content);
lst = lst->next;
}
return (0);
}*/
