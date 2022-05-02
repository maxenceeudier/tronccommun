/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:32:17 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 14:34:05 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>

int main(void)
{
char str[50] = "GeeksForGeeks is for programming geeks.";
printf("\nBefore memset(): %s\n", str);

// Fill 8 characters starting from str[13] with '.'
ft_memset(str + 13, 'A', 42*sizeof(char));

printf("After memset():  %s", str);
return 0;
}*/