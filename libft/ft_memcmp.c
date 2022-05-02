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

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n - 1 && ((char *)s1)[i] == ((char *)s2)[i])
	{
		if (((char *)s1)[i] == 0)
			return (0);
		i++;
	}
	return (((char *)s1)[i] - ((char *)s2)[i]);
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
