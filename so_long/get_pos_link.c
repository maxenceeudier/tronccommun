/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:15:03 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 16:30:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	get_pos(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.size_total)
	{
		if (vars->map.map[i / vars->map.num_col][i % vars->map.num_col] == 'P')
		{
			vars->pos.x = i % vars->map.num_col * vars->ob.img_width;
			vars->pos.y = i / vars->map.num_col * vars->ob.img_height;
			break ;
		}
		i++;
	}
}
