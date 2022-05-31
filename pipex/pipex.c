/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:10:31 by meudier           #+#    #+#             */
/*   Updated: 2022/05/31 16:43:42 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
    int     file;
    int     i;
    int     len;
    char    **arg;
    char    **path;
    char    **cmd;
    char    *cmd_path;
    char    *temp;

    cmd = ft_split(av[1], ' ');
    len = 0;
    while (cmd[len])
        len++;
    i = 0;
    while (ft_strncmp(env[i], "PATH", 4))
        i++;
    path = ft_split(env[i] + 5, ':');
    cmd_path = NULL;
    i = 0;
    while (path[i])
    {
        temp = cmd_path;
        cmd_path = ft_strjoin(path[i], cmd[0]);
        free (temp);
        if (!access(cmd_path, F_OK | X_OK))
            break ;
        i++;
    }
    free_tab(path);
    if (access(cmd_path, F_OK | X_OK) == -1)
        printf("this cmd do not exist");
    
    arg = (char **)malloc(sizeof(char *) * (len + 1));
    arg[0] = cmd_path;
    i = 1;
    while (i < len)
    {
        arg[i] = cmd[i];
        i++;
    }
    arg[i + 1] = NULL;
    file = open(av[ac - 1], O_WRONLY | O_CREAT, 0777);
    if (file == -1)
        return (1);
    dup2(file, 1);
    close(file);
    execve(cmd_path, arg, NULL);

    return (0);
}