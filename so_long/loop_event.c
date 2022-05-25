/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:13:35 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 16:31:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	handle_event(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->pos.x;
	y = vars->pos.y;
	mlx_clear_window(vars->mlx, vars->win);
	print_background(vars);
	print_decord(vars);
	print_fire(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, x, y);
	return (0);
}

int	loop_end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
