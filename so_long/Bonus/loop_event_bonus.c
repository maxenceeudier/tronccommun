/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:13:35 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 14:16:36 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int	handle_event(t_vars *vars)
{
	print_decord(vars);
	print_fire(vars);
	return (0);
}

int	loop_end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
