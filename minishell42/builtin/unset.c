/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:37:59 by meudier           #+#    #+#             */
/*   Updated: 2022/07/19 15:30:19 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	unset(t_parser *parser, int *built, t_vars *vars)
{
	int	i;

	*built = 1;
	if (!parser->arg[1])
		return (0);
	i = 1;
	while (parser->arg[i])
	{
		if (!check_unset(parser->arg[i]))
		{
			write(2, "minishell: unset: '", 19);
			write(2, parser->arg[i], ft_strlen(parser->arg[i]));
			write(2, "': not a valid identifier\n", 26);
			return (1);
		}
		remove_if(parser->arg[i], &(vars->envl), &ft_strcmp);
		remove_if(parser->arg[i], &(vars->var), &ft_strcmp);
		i++;
	}
	return (0);
}
