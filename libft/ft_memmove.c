/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:30 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 14:40:51 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len && ((char *)src)[i])
	{
		temp[i] = ((char *)src)[i];
		i++;
	}
	if (!((char *)src)[i])
		temp[i] = 0;
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = temp[i];
		i++;
	}
	return (dst);
}
// int main ()
// {
//   char str[] = "memmove can be very useful......";
//   ft_memmove (str+20,str+15,11);
//   puts (str);
//   return 0;
// }
