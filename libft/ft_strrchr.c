/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:33:17 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 13:48:44 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((char)c == s[i])
			return ((char *)(s + i));
		i--;
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

ret = ft_strrchr(str, ch);

printf("|%c| 之后的字符串是 |%s|\n", ch, ret);

return(0);
}*/
