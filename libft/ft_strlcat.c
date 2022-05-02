/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:41:31 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 14:42:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (j + i < dstsize - 1 && src[j] && dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	while (src[j])
		j++;
	if (dstsize < i)
		return (dstsize + j);
	return (j + i);
}
/*
#include <stdio.h>

int main()
{
char    s1[100] = "1234";
char    s2[100] = "ABCD";
int     rslt;

rslt = ft_strlcat(s1, s2, 2);
printf("retour = %d", rslt);
printf("\ndst = %s", s1);
return (0);
}*/
