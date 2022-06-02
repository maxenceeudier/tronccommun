/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:45:53 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 14:56:36 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	t_exec	vars;
	t_fds	fd;

	if (ac != 5)
	{
		ft_printf("You must write 4 args");
		return (0);
	}
	vars.env = env;
	vars.av = av;
	vars.num_of_process = ac - 3;
	fd.pipes = get_pipes(vars.num_of_process);
	if (!fd.pipes)
	{
		ft_printf("\nError of pipes\n");
		return (free_tab_int(fd.pipes, vars.num_of_process + 1));
	}
	if (!create_process(&fd, &vars))
	{
		ft_printf("\nError of execution of process\n");
		return (free_tab_int(fd.pipes, vars.num_of_process + 1));
	}
	free_tab_int(fd.pipes, vars.num_of_process + 1);
	return (0);
}
