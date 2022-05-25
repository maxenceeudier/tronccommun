/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:02:02 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 17:22:14 by meudier          ###   ########.fr       */
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
	i = &vars->f.img_width;
	j = &vars->f.img_height;
	vars->f.img = mlx_xpm_file_to_image(vars->mlx, vars->f.img_path, i, j);
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

void	get_j_k(int *j, int *k, int i, int x)
{
	*j = (i % x) * 64;
	*k = (i / x) * 64;
}

void	print_decord(t_vars *vars)
{
	int	i;
	int	x;
	int	j;
	int	k;

	i = -1;
	x = vars->map.num_col;
	while (++i < vars->map.size_total)
	{
		if ((vars->map.map)[i / x][i % x] == '1')
		{
			get_j_k(&j, &k, i, x);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->ob.img, j, k);
		}
		else if ((vars->map.map)[i / x][i % x] == 'C')
		{
			get_j_k(&j, &k, i, x);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->key.img, j, k);
		}
		else if ((vars->map.map)[i / x][i % x] == 'E')
		{
			get_j_k(&j, &k, i, x);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->d.img, j, k);
		}
	}
}
