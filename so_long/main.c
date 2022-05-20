#include <mlx.h>
#include <mlx_int.h>
#include <X11/keysym.h>

#define WIDTH 1280
#define HEIGHT 896
#define GREEN 0x00560000

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*win2;
	void	*img;
	void	*background;
	int		img_width;
	int		img_height;
	char	*img_path;
	char	*background_path;
	int		background_width;
	int		background_height;
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
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

int	key_move(int keycode, t_vars *vars)
{
	int i;
	int j;

	if (keycode == 115)
	{
		vars->img_path = "./img/front_static1.xpm";
		if (vars->j <= HEIGHT - 64)
			vars->j += 64;
	}
	if (keycode == 100)
	{
		vars->img_path = "./img/right_static.xpm";
		if (vars->i <= WIDTH - 64)
			vars->i += 64;
	}
	if (keycode == 97)
	{
		vars->img_path = "./img/left_static.xpm";
		if (vars->i >= 64)
			vars->i -= 64;
	}
	if (keycode == 119)
	{
		vars->img_path = "./img/back_static.xpm";
		if (vars->j >= 64)
			vars->j -= 64;
	}
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_image(vars->mlx, vars->background);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}

	mlx_destroy_image(vars->mlx, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	i = 0;
	while (vars->background_width + i <= WIDTH)
	{
		j = 0;
		while (vars->background_height + j <= HEIGHT)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background, 0 + i, 0 + j);
			j += vars->background_height;
		}
		i += vars->background_width;
	}
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0 + vars->i, 0 + vars-> j);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		i;
	int		j;

	vars.background_path = "./img/herbe.xpm";
	vars.img_path = "./img/front_static1.xpm";
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
	if (!vars.win)
	{
		free (vars.win);
		return (1);
	}
	vars.i = 5;
	vars.j = 5;
	vars.background = mlx_xpm_file_to_image(vars.mlx, vars.background_path, &vars.background_width, &vars.background_height);
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.img_path, &vars.img_width, &vars.img_height);
	
	
	i = 0;
	while (vars.background_width + i <= WIDTH)
	{
		j = 0;
		while (vars.background_height + j <= HEIGHT)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.background, 0 + i, 0 + j);
			j += vars.background_height;
		}
		i += vars.background_width;
	}
	
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 10, 10);
	
	
	mlx_key_hook(vars.win, key_move, &vars);


	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free (vars.mlx);
}