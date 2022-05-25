/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:07:39 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 17:06:53 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	init(t_vars *vars, int ac, char **av)
{
	if (!get_map(vars, ac, av))
		return (0);
	vars->map.size_total = vars->map.num_col * vars->map.num_row;
	vars->width = vars->map.num_col * 64;
	vars->heigth = vars->map.num_row * 64;
	vars->bg.img_path = "./img/herbe.xpm";
	vars->img.img_path = "./img/front_static1.xpm";
	vars->ob.img_path = "./img/brick.xpm";
	vars->key.img_path = "./img/key.xpm";
	vars->d.img_path = "./img/door.xpm";
	vars->f.img_path = "./img/fire.xpm";
	vars->nb_of_mouv = 0;
	return (1);
}
