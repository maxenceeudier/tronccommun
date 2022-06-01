/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:34:48 by meudier           #+#    #+#             */
/*   Updated: 2022/06/01 17:58:43 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    dup_fd(int i, int num_of_process, int **pipes, int in_file, int out_file)
{
    if (i == 0)
        dup2(in_file, 0);
    else
        dup2(pipes[i][0], 0);
    if (i == num_of_process - 1)
        dup2(out_file, 1);
    else
        dup2(pipes[i + 1][1], 1);
}

int create_process(int num_of_process, int **pipes, char **av, char **env)
{
    int     *pids;
    int     i;
    int     in_file;
    int     out_file;
    
    int     j;
    int     len;
    char    **arg;
    char    **path;
    char    **cmd;
    char    *cmd_path;
    char    *temp;

    if (!get_file_fd(&in_file, &out_file, av, num_of_process + 3))
        return (0);
    pids = (int *)calloc(sizeof(int), num_of_process);
    if (!pids)
        return (0);
    i = 0;
    while (i < num_of_process)
    {
        pids[i] = fork();
        if (pids[i] == 0)
        {
            cmd = ft_split(av[i + 2], ' ');
            if (!cmd)
            {
                free(pids);
                return (0);
            }
            
            len = 0;
            while (cmd[len])
                len++;
        
            j = 0;
            while (ft_strncmp(env[j], "PATH", 4))
                j++;
                
            path = ft_split(env[j] + 5, ':');
            if (!path)
            {
                free(pids);
                free_tab(cmd);
                return (0);
            }
            
            cmd_path = NULL;
            j = 0;
            while (path[j])
            {
                temp = cmd_path;
                cmd_path = ft_strjoin(path[j], cmd[0]);
                free (temp);
                if (!cmd)
                {
                    free(pids);
                    free_tab(cmd);
                    free_tab(path);
                    return (0);
                }
                if (!access(cmd_path, F_OK | X_OK))
                    break ;
                j++;
            }
            free_tab(path);
            if (access(cmd_path, F_OK | X_OK) == -1)
            {
                ft_printf("the cmd %s do not exist\n", cmd_path);
                free(pids);
                return (0);
            }
            arg = (char **)malloc(sizeof(char *) * (len + 1));
            arg[0] = cmd_path;
            j = 1;
            while (j < len)
            {
                arg[j] = cmd[j];
                j++;
            }
            arg[j] = NULL;
            
            j = 0;
            int k;
            while (j < num_of_process + 1)
            {
                k = 0;
                while (k < 2)
                    printf("%d\n", pipes[j][k++]);
                j++;
            }
                    
            dup_fd(i, num_of_process, pipes, in_file, out_file);
            close_all_fd(pipes, num_of_process, in_file, out_file);
            free(pids);
            free_tab(cmd);
            execve(cmd_path, arg, NULL);
            return (0);
        }
        waitpid(pids[i], NULL, 0);
        close_all_fd(pipes, num_of_process, in_file, out_file);
        i++;
    }
    free(pids);
    return (1);
}