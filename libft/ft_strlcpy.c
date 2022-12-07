/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:46:55 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 13:46:27 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i] && i < len - 1 && len)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < len)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int main(void)
{
char src[50] = "GeeksForGeeks is for programming geeks.";
char dst[50] = "coucou";
printf("\nBefore strcpy(): %s\n", dst);
ft_strlcpy(dst, src, 5);
printf("\nAfter strcpy(): %s\n", dst);
}*/
