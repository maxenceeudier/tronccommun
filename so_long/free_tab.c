/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:09:39 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 14:10:20 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_tab(t_vars *vars)
{
	int	i;

	i = 0;
	while ((vars->map.map)[i])
		free ((vars->map.map)[i++]);
	free(vars->map.map);
}