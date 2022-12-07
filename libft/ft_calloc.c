/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:59:47 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 08:15:44 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*adrs;
	size_t	i;

	if (size * count == SIZE_MAX * SIZE_MAX)
		return (NULL);
	adrs = (char *)malloc(size * count);
	if (!adrs)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		adrs[i] = 0;
		i++;
	}
	return ((void *)adrs);
}

/*
#include <stdio.h>  
#include <stdint.h>       
#include <stdlib.h>

int main() {

int i;
int * pointer =  ft_calloc(6, 6);

for (i=0; i<10; i++ ) {
printf( "%d ", pointer[i] );
}
printf( "\n" );
free( pointer );

return 0;
}
*/
