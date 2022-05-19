#include <mlx.h>
#include <mlx_int.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*win2;
	void	*img;
	int		img_width;
	int		img_height;
	char	*relative_path;
	int		i;
	int		j;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 115)
	{
		vars->relative_path = "./img/sprites_pause1.xpm";
		vars->j += 10;
	}
	if (keycode == 100)
	{
		vars->relative_path = "./img/sprites_R1.xpm";
		vars->i += 10;
	}
	if (keycode == 97)
		vars->i -= 10;
	if (keycode == 119)
		vars->j -= 10;
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->relative_path, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0 + vars->i, 0 + vars-> j);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.relative_path = "./img/sprites_pause1.xpm";
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 800, "Hello world!");
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.relative_path, &vars.img_width, &vars.img_height);
	vars.i = 10;
	vars.j = 10;

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 10, 10);

	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);
}