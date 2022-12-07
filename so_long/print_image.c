/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:08:50 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 11:39:23 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	create_img(t_vars *vars)
{
	int	*i;
	int	*j;

	i = &vars->bg.img_width;
	j = &vars->bg.img_height;
	vars->bg.img = mlx_xpm_file_to_image(vars->mlx, vars->bg.img_path, i, j);
	i = &vars->img.img_width;
	j = &vars->img.img_height;
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, vars->img.img_path, i, j);
	i = &vars->ob.img_width;
	j = &vars->ob.img_height;
	vars->ob.img = mlx_xpm_file_to_image(vars->mlx, vars->ob.img_path, i, j);
	i = &vars->key.img_width;
	j = &vars->key.img_height;
	vars->key.img = mlx_xpm_file_to_image(vars->mlx, vars->key.img_path, i, j);
	i = &vars->d.img_width;
	j = &vars->d.img_height;
	vars->d.img = mlx_xpm_file_to_image(vars->mlx, vars->d.img_path, i, j);
}

void	print_background(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->bg.img_width + i <= vars->width)
	{
		j = 0;
		while (vars->bg.img_height + j <= vars->heigth)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg.img, i, j);
			j += vars->bg.img_height;
		}
		i += vars->bg.img_width;
	}
}

void	print_assets_whith_bg(t_vars *vars, int i, int x, void *img)
{
	int	k;
	int	j;

	j = (i % x) * 64;
	k = (i / x) * 64;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg.img, j, k);
	mlx_put_image_to_window(vars->mlx, vars->win, img, j, k);
}

void	print_assets(t_vars *vars, int i, int x, void *img)
{
	int	k;
	int	j;

	j = (i % x) * 64;
	k = (i / x) * 64;
	mlx_put_image_to_window(vars->mlx, vars->win, img, j, k);
}

void	print_decord(t_vars *vars)
{
	int	i;
	int	x;

	i = -1;
	x = vars->map.num_col;
	while (++i < vars->map.size_total)
	{
		if ((vars->map.map)[i / x][i % x] == '1')
			print_assets(vars, i, x, vars->ob.img);
		else if ((vars->map.map)[i / x][i % x] == 'C')
			print_assets_whith_bg(vars, i, x, vars->key.img);
		else if ((vars->map.map)[i / x][i % x] == 'E')
			print_assets_whith_bg(vars, i, x, vars->d.img);
		else if ((vars->map.map)[i / x][i % x] == 'P')
			print_assets_whith_bg(vars, i, x, vars->img.img);
		else if ((vars->map.map)[i / x][i % x] == '0')
			print_assets(vars, i, x, vars->bg.img);
	}
}
