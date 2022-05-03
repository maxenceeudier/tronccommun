/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:47:05 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 15:48:38 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main ()
{
char buffer1[] = "DWgaOtP12df0";
char buffer2[] = "DWgOOtP12df0";

int n;

n = ft_memcmp( buffer1, buffer2, 4 );

if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);

return 0;
}*/
