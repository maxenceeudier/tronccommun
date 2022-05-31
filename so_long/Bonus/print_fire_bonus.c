/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fire_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:02:12 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 11:31:43 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	mlx_put_img_to_win(t_vars *vars, int i, int x, int add)
{
	int	k;
	int	l;

	k = (i % x) * 64;
	l = (i / x + add) * 64;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->f.img, k, l);
}

void	put_fire(int i, int x, int *j, t_vars *vars)
{
	static int	clear = 0;

	clear ++;
	if (*j > SPEED * 4
		&& *j <= SPEED * 8 && (vars->map.map)[i / x + 1][i % x] == '0')
	{
		(vars->map.map)[i / x][i % x] = '0';
		(vars->map.map)[i / x + 1][i % x] = 'N';
		if (!clear)
			mlx_clear_window(vars->mlx, vars->win);
		clear++;
	}
	else if (*j > SPEED * 8
		&& *j <= SPEED * 12 && (vars->map.map)[i / x - 1][i % x] == '0')
	{
		(vars->map.map)[i / x][i % x] = '0';
		(vars->map.map)[i / x - 1][i % x] = 'N';
		if (clear == 1)
			mlx_clear_window(vars->mlx, vars->win);
	}
	else if (*j > SPEED * 12)
	{
		*j = 0;
		clear = 0;
	}
}

void	print_fire(t_vars *vars)
{
	int			i;
	int			x;
	static int	j = 0;

	j++;
	i = -1;
	x = vars->map.num_col;
	while (++i < vars->map.size_total)
	{
		if ((vars->map.map)[i / x][i % x] == 'N')
			put_fire(i, x, &j, vars);
	}
}
