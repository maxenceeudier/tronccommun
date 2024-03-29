/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:31:21 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 13:39:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	while (s && s[i])
		i++;
	j = 0;
	while (s && j <= i)
	{
		if ((char)c == s[j])
			return ((char *)(s + j));
		j++;
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

ret = ft_strchr(str, ch);

printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);

return(0);
}*/
