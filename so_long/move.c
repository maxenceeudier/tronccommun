/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:00:30 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 16:42:36 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	move_front(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/front_static1.xpm";
	if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] != '1'
		&& vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] != 'N'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] == 'E'))
		vars->pos.y += size;
	else if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
}

void	move_back(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/back_static.xpm";
	if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] != '1'
		&& vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] != 'N'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] == 'E'))
		vars->pos.y -= size;
	else if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
}

void	move_right(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/right_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] != '1'
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] != 'N'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] == 'E'))
		vars->pos.x += size;
	else if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
}

void	move_left(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/left_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] != '1'
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] != 'N'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] == 'E'))
		vars->pos.x -= size;
	else if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
}
