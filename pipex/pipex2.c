/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:45:53 by meudier           #+#    #+#             */
/*   Updated: 2022/06/01 17:25:01 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
    int     num_of_process;
    int     **pipes;

    num_of_process = ac - 3;
    pipes = get_pipes(num_of_process);
    if (!pipes)
        return (free_tab_int(pipes, num_of_process + 1));
    
    if (!create_process(num_of_process, pipes, av, env))
        return (free_tab_int(pipes, num_of_process + 1));
    free_tab_int(pipes, num_of_process + 1);
    return (0);
}