/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:13:34 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 13:08:43 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	handle_event(t_vars *vars)
{
	print_decord(vars);
	return (0);
}

int	loop_end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
