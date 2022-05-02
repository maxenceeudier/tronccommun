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

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((char *)src)[i])
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	if (!((char *)src)[i])
		((char *)dst)[i] = 0;
	return (dst);
}
// #include <stdio.h>

// int main(void)
// {
//     char src[50] = "GeeksForGeeks is for programming geeks.";
//     char dst[50] = "coucou";
//     printf("\nBefore memcpy(): %s\n", dst);
//     ft_memcpy(dst, src, 3);
//     printf("\nAfter memcpy(): %s\n", dst);
// }
