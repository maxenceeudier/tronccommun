/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:30:42 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 17:07:19 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FR_H
# define SPEED 30
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <mlx_int.h>
# include <X11/keysym.h>

typedef struct s_image
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*img_path;
}	t_image;

typedef struct s_map
{
	char	**map;
	int		num_col;
	int		num_row;
	int		size_total;
	int		num_of_c;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_image	bg;
	t_image	ob;
	t_image	key;
	t_image	d;
	t_image	f;
	t_map	map;
	t_pos	pos;
	int		width;
	int		heigth;
	int		i;
	int		j;
	int		nb_of_mouv;
}	t_vars;

typedef struct s_data_map
{
	int	last;
	int	first;
	int	num_of_c;
	int	num_of_p;
	int	num_of_e;
	int	width;
	int	heigth;
}	t_data_map;

char	**ft_split(char const *s, char c);
int		get_map(t_vars *vars, int ac, char **av);
void	free_tab(t_vars *vars);
int		is_rip(char *str);
int		loop_end(t_vars *vars);
int		destroy(t_vars *vars);
int		door_is_close(char *str);
void	print_background(t_vars *vars);
void	print_decord(t_vars *vars);
void	print_fire(t_vars *vars);
int		key_move(int keycode, t_vars *vars);
void	move_front(t_vars *vars, int size);
void	move_back(t_vars *vars, int size);
void	move_right(t_vars *vars, int size);
void	move_left(t_vars *vars, int size);
void	create_img(t_vars *vars);
void	get_pos(t_vars *vars);
int		init(t_vars *vars, int ac, char **av);
int		handle_event(t_vars *vars);
int		loop_end(t_vars *vars);
int		line_is_first(char *str);
int		init_map(t_data_map *map, int *i, char **line, char *file);
int		extension_is_good(char *str);
int		is_good_extension(char *str);
int		line_is_ok(char *line, t_data_map *map, int num_of_line);
int		get_first_line(t_data_map *map, char **line, int fd);
int		get_others_lines(char **line, int fd);
int		free_and_close(char *line, int fd);
void	key_move_action(int keycode, t_vars *vars, int size);

#endif
