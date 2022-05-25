/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:41:30 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 17:07:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->bg.img);
	mlx_destroy_image(vars->mlx, vars->ob.img);
	mlx_destroy_image(vars->mlx, vars->key.img);
	mlx_destroy_image(vars->mlx, vars->d.img);
	mlx_destroy_image(vars->mlx, vars->f.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	free_tab(vars);
	return (0);
}
