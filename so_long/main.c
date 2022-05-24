#include <mlx.h>
#include <mlx_int.h>
#include <X11/keysym.h>
#include "ft.h"

int	handle_no_event(t_vars *vars)
{
	(void)vars;
	return (0);
}

int	loop_end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
int	destroy(t_vars *vars)
{
	if (is_rip(vars->img.img_path))
		sleep(3);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->obstacle.img);
	mlx_destroy_image(vars->mlx, vars->key.img);
	mlx_destroy_image(vars->mlx, vars->door.img);
	mlx_destroy_image(vars->mlx, vars->fire.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	free_tab(vars);
	return (0);
}

int	door_is_close(char *str)
{
	char	*door;
	int		i;

	i = 0;
	door = "./img/door.xpm";
	while (str[i] == door[i])
	{
		if (str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_rip(char *str)
{
	char	*rip;
	int		i;

	i = 0;
	rip = "./img/rip.xpm";
	while (str[i] == rip[i])
	{
		if (str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

void	move_front(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/front_static1.xpm";
	if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] != '1'
		&& vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] != 'N'
		&& !(door_is_close(vars->door.img_path) 
		&& vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] == 'E'))
		vars->pos.y += size;
	else if (vars->map.map[vars->pos.y / size + 1][vars->pos.x / size] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size ][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
	
}

void	move_back(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/back_static.xpm";
	if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] != '1'
		&& vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] != 'N'
		&& !(door_is_close(vars->door.img_path) 
		&& vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] == 'E'))
		vars->pos.y -= size;
	else if (vars->map.map[vars->pos.y / size - 1][vars->pos.x / size] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size ][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
}

void	move_right(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/right_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] != '1'
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] != 'N'
		&& !(door_is_close(vars->door.img_path) 
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] == 'E'))
		vars->pos.x += size;
	else if (vars->map.map[vars->pos.y / size][vars->pos.x / size + 1] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size ][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
}

void	move_left(t_vars *vars, int size)
{
	vars->nb_of_mouv++;
	vars->img.img_path = "./img/left_static.xpm";
	if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] != '1'
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] != 'N'
		&& !(door_is_close(vars->door.img_path) 
		&& vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] == 'E'))
		vars->pos.x -= size;
	else if (vars->map.map[vars->pos.y / size][vars->pos.x / size - 1] == 'N')
		vars->img.img_path = "./img/rip.xpm";
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'C')
	{
		(vars->map.map)[vars->pos.y / size ][vars->pos.x / size] = '0';
		vars->map.num_of_c--;
	}
	if (vars->map.map[vars->pos.y / size ][vars->pos.x / size] == 'E'
		&& vars->map.num_of_c == 0)
		loop_end(vars);
	
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

void	print_decord(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.size_total)
	{
		if ((vars->map.map)[i / vars->map.num_col][i % vars->map.num_col] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->obstacle.img, 0 + (i % vars->map.num_col) * 64, 0 + (i / vars->map.num_col) * 64);
		else if ((vars->map.map)[i / vars->map.num_col][i % vars->map.num_col] == 'C')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->key.img, 20 + (i % vars->map.num_col) * 64, 20 + (i / vars->map.num_col) * 64);
		else if ((vars->map.map)[i / vars->map.num_col][i % vars->map.num_col] == 'E')
		{
			if (vars->map.num_of_c == 0)
			{
				mlx_destroy_image(vars->mlx, vars->door.img);
				vars->door.img_path = "./img/dooropen.xpm";
				vars->door.img = mlx_xpm_file_to_image(vars->mlx, vars->door.img_path, &vars->door.img_width, &vars->door.img_height);
			}
			mlx_put_image_to_window(vars->mlx, vars->win, vars->door.img, 0 + (i % vars->map.num_col) * 64, 0 + (i / vars->map.num_col) * 64);
		}
		else if ((vars->map.map)[i / vars->map.num_col][i % vars->map.num_col] == 'N')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->fire.img, 0 + (i % vars->map.num_col) * 64, 0 + (i / vars->map.num_col) * 64);
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
		return (loop_end(vars));
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_clear_window(vars->mlx, vars->win);
	print_background(vars);
	print_decord(vars);
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, vars->img.img_path, &vars->img.img_width, &vars->img.img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0 + vars->pos.x , 0 + vars->pos.y);
	if (is_rip(vars->img.img_path))
		loop_end(vars);
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
	vars->key.img_path = "./img/key.xpm";
	vars->door.img_path = "./img/door.xpm";
	vars->fire.img_path = "./img/fire.xpm";
	vars->nb_of_mouv = 0;
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
	vars->key.img = mlx_xpm_file_to_image(vars->mlx, vars->key.img_path, &vars->key.img_width, &vars->key.img_height);
	vars->door.img = mlx_xpm_file_to_image(vars->mlx, vars->door.img_path, &vars->door.img_width, &vars->door.img_height);
	vars->fire.img = mlx_xpm_file_to_image(vars->mlx, vars->fire.img_path, &vars->fire.img_width, &vars->fire.img_height);
}

void	free_tab(t_vars *vars)
{
	int	i;

	i = 0;
	while ((vars->map.map)[i])
		free ((vars->map.map)[i++]);
	free(vars->map.map);
}


#include <stdio.h>

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
	//loop_hook make animation
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_key_hook(vars.win, key_move, &vars);
	mlx_hook(vars.win, 17, 1L>>17, loop_end,&vars);
	mlx_loop(vars.mlx);
	destroy(&vars);
	printf("Vous avez fait : %d deplacements\n", vars.nb_of_mouv);
	if (is_rip(vars.img.img_path))
		printf("\nYOU LOOSE");
	else
		printf("\nYOU WIN");
	return (0);
}