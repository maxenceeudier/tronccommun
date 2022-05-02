/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:44:58 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 15:46:29 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((char *)s)[i])
	{
		if ((unsigned char)c == ((char *)s)[i])
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main ()
{
const char str[] = "http://www.w3cschool.cc";
const char ch = '.';
char *ret;

ret = ft_memchr(str, ch, strlen(str));

printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);

return(0);
}*/
