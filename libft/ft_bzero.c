/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:34:46 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 14:35:13 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}
// #include <stdio.h>

//  int main()
//  {
//     int i = 0;
//     char str[] = "hello";
//     while (i < sizeof(str))
//         printf("%c", str[i++]);
//     printf("\n");
//     ft_bzero(str, sizeof(str));
//     i = 0;
//     while (i < sizeof(str))
//         printf("%d", str[i++]);
//     printf("\n");
//     return (0);
//  }
