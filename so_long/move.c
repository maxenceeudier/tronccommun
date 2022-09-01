/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:11:56 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 14:26:46 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	move_front(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/front_static1.xpm";
	if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] != '1'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] == 'E'))
	{
		if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] == 'C')
			vars->map.num_of_c--;
		if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] == 'E'
			&& vars->map.num_of_c == 0)
		{
			vars->succes = 1;
			loop_end(vars);
		}
		vars->map.map[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] = 'P';
		vars->pos.y += size;
	}
}

void	move_back(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/back_static.xpm";
	if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] != '1'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] == 'E'))
	{
		if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] == 'C')
			vars->map.num_of_c--;
		if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] == 'E'
			&& vars->map.num_of_c == 0)
		{
			vars->succes = 1;
			loop_end(vars);
		}
		vars->map.map[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] = 'P';
		vars->pos.y -= size;
	}
}

void	move_right(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/right_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] != '1'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] == 'E'))
	{
		if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] == 'C')
			vars->map.num_of_c--;
		if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] == 'E'
			&& vars->map.num_of_c == 0)
		{
			vars->succes = 1;
			loop_end(vars);
		}
		vars->map.map[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] = 'P';
		vars->pos.x += size;
	}
}

void	move_left(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/left_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] != '1'
		&& !(door_is_close(vars->d.img_path)
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] == 'E'))
	{
		if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] == 'C')
			vars->map.num_of_c--;
		if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] == 'E'
			&& vars->map.num_of_c == 0)
		{
			vars->succes = 1;
			loop_end(vars);
		}
		vars->map.map[vars->pos.y / size][vars->pos.x / size] = '0';
		vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] = 'P';
		vars->pos.x -= size;
	}
}
