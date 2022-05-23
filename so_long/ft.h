/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:30:42 by meudier           #+#    #+#             */
/*   Updated: 2022/05/23 18:18:22 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FR_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

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

typedef struct s_data_map
{
    int last;
    int first;
    int num_of_c;
    int num_of_p;
    int num_of_e;
    int width;
    int heigth;
}   t_data_map;

char	**ft_split(char const *s, char c);
int     get_map(t_vars *vars, int ac, char **av);

#endif