/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:21:17 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 14:31:10 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_printf/ft_printf.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (!init(&vars, ac, av))
		return (0);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.heigth, "My ZELDA !!");
	if (!vars.win)
		return (1);
	create_img(&vars);
	get_pos(&vars);
	mlx_key_hook(vars.win, key_move, &vars);
	mlx_loop_hook(vars.mlx, &handle_event, &vars);
	mlx_hook(vars.win, 17, 1L >> 17, loop_end, &vars);
	mlx_loop(vars.mlx);
	destroy(&vars);
	if (is_rip(vars.img.img_path))
		ft_printf("\nVous avez fait : %d deplacements\n\n   *********\n\
   YOU LOOSE\n   *********\n\n", vars.nb_of_mouv);
	else if (vars.succes)
		ft_printf("\nVous avez fait : %d deplacements\n\n   *********\n\
   *YOU WIN*\n   *********\n\n", vars.nb_of_mouv);
	return (0);
}
