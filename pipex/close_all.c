/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:37:30 by meudier           #+#    #+#             */
/*   Updated: 2022/06/01 17:24:54 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void    close_all_fd(int **pipes, int num_of_process, int in_file, int out_file)
{
    int j;

    close(in_file);
    close(out_file);
    j = 0;
    while (j < num_of_process + 1)
    {
        close(pipes[j][0]);
        close(pipes[j][1]);
        j++;
    }
}