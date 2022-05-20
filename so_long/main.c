#include <mlx.h>
#include <mlx_int.h>
#include <X11/keysym.h>
#include "ft.h"

#define WIDTH 1280
#define HEIGHT 896
#define GREEN 0x00560000

typedef struct	s_image
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*img_path;
}	t_image;

typedef struct	s_map
{
	char	**map;
	int		num_col;
	int		num_row;
	int		size_total;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_image	background;
	t_image obstacle;
	t_map	map;
	t_pos	pos;
	int		width;
	int		heigth;
	int		i;
	int		j;
}				t_vars;


int	handle_no_event(void *data)
{
	(void)data;
	/* This function is to close the prog*/
	return (0);
}

int	handle_input(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

/*int	check_move(t_vars *vars)
{
	
}*/

int	key_move(int keycode, t_vars *vars)
{
	int i;
	int j;

	i = 0;
	if (keycode == 115)
	{
		vars->img.img_path = "./img/front_static1.xpm";
		if (vars->map.map[vars->pos.y / 64 + 1][vars->pos.x / 64] != '1')
			vars->pos.y += 64;
	}
	if (keycode == 100)
	{
		vars->img.img_path = "./img/right_static.xpm";
		if (vars->map.map[vars->pos.y / 64][vars->pos.x / 64 + 1] != '1')
			vars->pos.x += 64;
	}
	if (keycode == 97)
	{
		vars->img.img_path = "./img/left_static.xpm";
		if (vars->map.map[vars->pos.y / 64][vars->pos.x / 64 - 1] != '1')
			vars->pos.x -= 64;
	}
	if (keycode == 119)
	{
		vars->img.img_path = "./img/back_static.xpm";
		if (vars->map.map[vars->pos.y / 64 - 1][vars->pos.x / 64] != '1')
			vars->pos.y -= 64;
	}
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_image(vars->mlx, vars->background.img);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_clear_window(vars->mlx, vars->win);
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
	i = 0;
	while (i < vars->map.size_total)
	{
		if ((vars->map.map)[i / vars->map.num_col][i % vars->map.num_col] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->obstacle.img, 0 + (i % vars->map.num_col) * 64, 0 + (i / vars->map.num_col) * 64);
		i++;
	}
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, vars->img.img_path, &vars->img.img_width, &vars->img.img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0 + vars->pos.x, 0 + vars->pos.y);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*str = "11111111111111111111\n10000000001000000011\n100p0000000000000101\n10000000001000000001\n11111111111111111111";
	int		i;

	vars.map.map = ft_split(str, '\n');
	vars.map.num_col = 20;
	vars.map.num_row = 5;
	vars.map.size_total = vars.map.num_col * vars.map.num_row;
	vars.i = 64;
	vars.j = 64;
	vars.width = vars.map.num_col * 64;
	vars.heigth = vars.map.num_row * 64;

	i = 0;
	while (i < vars.map.size_total)
	{
		if (vars.map.map[i / vars.map.num_col][i % vars.map.num_col] == 'p')
		{
			vars.pos.x = i % vars.map.num_col * 64;
			vars.pos.y = i / vars.map.num_col * 64;
			break ;
		}
		i++;
	}

	vars.background.img_path = "./img/herbe.xpm";
	vars.img.img_path = "./img/front_static1.xpm";
	vars.obstacle.img_path = "./img/brick.xpm";

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);

	vars.win = mlx_new_window(vars.mlx, vars.width, vars.heigth, "My own ZELDA !!");
	if (!vars.win)
	{
		free (vars.win);
		return (1);
	}

	vars.background.img = mlx_xpm_file_to_image(vars.mlx, vars.background.img_path, &vars.background.img_width, &vars.background.img_height);
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, vars.img.img_path, &vars.img.img_width, &vars.img.img_height);
	vars.obstacle.img = mlx_xpm_file_to_image(vars.mlx, vars.obstacle.img_path, &vars.obstacle.img_width, &vars.obstacle.img_height);
	
	mlx_key_hook(vars.win, key_move, &vars);

	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free (vars.mlx);
}