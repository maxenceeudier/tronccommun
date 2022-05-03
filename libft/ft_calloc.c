/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:59:47 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 16:01:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*adrs;
	size_t	i;

	adrs = (void *)malloc(size * count);
	if (!adrs)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*(char *)(adrs + i) = 0;
		i++;
	}
	return (adrs);
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