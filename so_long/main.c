#include <mlx.h>
#include <mlx_int.h>
#include <X11/keysym.h>
#include "ft.h"

int	handle_no_event(void *data)
{
	(void)data;
	/* This function is to close the prog*/
	return (0);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->obstacle.img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	move_front(t_vars *vars, int size)
{
	vars->img.img_path = "./img/front_static1.xpm";
	if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] != '1')
		vars->pos.y += size;
}

void	move_back(t_vars *vars, int size)
{
	vars->img.img_path = "./img/back_static.xpm";
	if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] != '1')
		vars->pos.y -= size;
}

void	move_right(t_vars *vars, int size)
{
	vars->img.img_path = "./img/right_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] != '1')
		vars->pos.x += size;
}

void	move_left(t_vars *vars, int size)
{
	vars->img.img_path = "./img/left_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] != '1')
		vars->pos.x -= size;
}

void	print_background(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->background.img_width + i <= vars->width)
	{
		j = 0;
		while (vars->background.img_height + j <= vars->heigth)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, 0 + i, 0 + j);
			j += vars->background.img_height;
		}
		i += vars->background.img_width;
	}
}

void	print_obstacle(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.size_total)
	{
		if ((vars->map.map)[i / vars->map.num_col][i % vars->map.num_col] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->obstacle.img, 0 + (i % vars->map.num_col) * 64, 0 + (i / vars->map.num_col) * 64);
		i++;
	}
}

int	key_move(int keycode, t_vars *vars)
{
	int	size;

	size = vars->obstacle.img_width;
	if (keycode == 115)
		move_front(vars, size);
	if (keycode == 100)
		move_right(vars, size);
	if (keycode == 97)
		move_left(vars, size);
	if (keycode == 119)
		move_back(vars, size);
	if (keycode == XK_Escape)
		return (destroy(vars));
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_clear_window(vars->mlx, vars->win);
	print_background(vars);
	print_obstacle(vars);
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, vars->img.img_path, &vars->img.img_width, &vars->img.img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0 + vars->pos.x, 0 + vars->pos.y);
	return (0);
}

int	init(t_vars *vars, int ac, char **av)
{
	if (!get_map(vars, ac, av))
		return (0);
	vars->map.size_total = vars->map.num_col * vars->map.num_row;
	vars->width = vars->map.num_col * 64;
	vars->heigth = vars->map.num_row * 64;
	vars->background.img_path = "./img/herbe.xpm";
	vars->img.img_path = "./img/front_static1.xpm";
	vars->obstacle.img_path = "./img/brick.xpm";
	return (1);
}

void	get_pos(t_vars *vars)
{
	int		i;

	i = 0;
	while (i < vars->map.size_total)
	{
		if (vars->map.map[i / vars->map.num_col][i % vars->map.num_col] == 'P')
		{
			vars->pos.x = i % vars->map.num_col * vars->obstacle.img_width;
			vars->pos.y = i / vars->map.num_col * vars->obstacle.img_height;
			break ;
		}
		i++;
	}
}

void	create_img(t_vars *vars)
{
	vars->background.img = mlx_xpm_file_to_image(vars->mlx, vars->background.img_path, &vars->background.img_width, &vars->background.img_height);
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, vars->img.img_path, &vars->img.img_width, &vars->img.img_height);
	vars->obstacle.img = mlx_xpm_file_to_image(vars->mlx, vars->obstacle.img_path, &vars->obstacle.img_width, &vars->obstacle.img_height);
}

void	free_tab(t_vars *vars)
{
	int	i;

	i = 0;
	while ((vars->map.map)[i])
		free ((vars->map.map)[i++]);
	free(vars->map.map);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (!init(&vars, ac, av))
	{
		if (write(2, "error\n", 6))
			return (0);
	}
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.heigth, "My own ZELDA !!");
	if (!vars.win)
		return (1);
	create_img(&vars);
	get_pos(&vars);
	mlx_key_hook(vars.win, key_move, &vars);
	mlx_hook(vars.win, 17, 0, destroy ,&vars);
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free (vars.mlx);
	free_tab(&vars);
	return (0);
}