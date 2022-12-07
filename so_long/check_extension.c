/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:33:54 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 12:36:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "ft.h"

int	extension_is_good(char *str)
{
	char	*ext;
	int		i;

	i = 0;
	ext = ".ber";
	while (str[i] == ext[i])
	{
		if (ext[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_good_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (extension_is_good(str + i))
			return (1);
		i++;
	}
	printf("Error\nthe extention of the map is wrong\n");
	return (0);
}
