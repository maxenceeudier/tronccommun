/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:55:17 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 14:04:12 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		write (fd, "(null)", 6);
	else
	{
		while (s[i])
			i++;
		write (fd, s, i);
	}
	write (fd, "\n", 1);
}
/*
   int main()
   {
   ft_putendl_fd("coucou", 1);
   return (0);
   }*/
