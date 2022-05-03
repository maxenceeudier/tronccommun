/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:36:20 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 14:37:04 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>

int main(void)
{
    char src[] = "bbbbbb";
    char dst[] = "AAA";
	printf("\nBefore memcpy(): %s\n", dst);
    ft_memcpy(dst, src, 2);
    printf("\nAfter memcpy(): %s\n", dst);
}
*/