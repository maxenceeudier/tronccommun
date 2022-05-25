/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:41:13 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 16:44:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	key_move_action(int keycode, t_vars *vars, int size)
{
	if (keycode == 115)
		move_front(vars, size);
	if (keycode == 100)
		move_right(vars, size);
	if (keycode == 97)
		move_left(vars, size);
	if (keycode == 119)
		move_back(vars, size);
}

int	key_move(int keycode, t_vars *vars)
{
	int	size;
	int	*i;
	int	*j;

	i = &vars->img.img_width;
	j = &vars->img.img_height;
	if (is_rip(vars->img.img_path))
		return (loop_end(vars));
	size = vars->ob.img_width;
	key_move_action(keycode, vars, size);
	if (keycode == XK_Escape)
		return (loop_end(vars));
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, vars->img.img_path, i, j);
	if (vars->map.num_of_c == 0)
	{
		i = &vars->d.img_width;
		j = &vars->d.img_height;
		mlx_destroy_image(vars->mlx, vars->d.img);
		vars->d.img_path = "./img/dooropen.xpm";
		vars->d.img = mlx_xpm_file_to_image(vars->mlx, vars->d.img_path, i, j);
	}
	return (0);
}
