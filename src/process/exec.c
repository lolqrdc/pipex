/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:46:38 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/03 11:03:12 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief 
 */

void    ft_execute(t_pipex *pipex, char **envp)
{
    t_cmd   *command;
    int     i;
    
    i = 0;
    command = pipex->cmd;
    pipex->pipes_fd = create_pipes(pipex);
    if (!pipex->pipes_fd)
        return ;
    while (i < pipex->count_cmd)
    {
        handle_fork(pipex, envp, i);            
        command = command->next;
        i++;
    }
    wait_children(pipex);
    close_pipes(pipex);
    ft_cleanup(pipex);
}
int handle_fork(t_pipex *pipex, char **envp, int i)
{
    pipex->pids[i] = fork();
    if (pipex->pids[i] == 0)
    {
        child_process(pipex, envp, i);
        exit(EXIT_FAILURE);
    }
    else if (pipex->pids[i] < 0)
    {
        perror("fork");
        return (1);
    }
    return (0);
}

int **create_pipes(t_pipex *pipex)
{
    int **pipes;
    int i;

    pipes = malloc(sizeof(int *)* pipex->count_cmd - 1);
    if (!pipes)
        return (NULL);
    i = 0;
    while (i < pipex->count_cmd - 1)
    {
        pipes[i] = malloc(sizeof(int)* 2);
        if (!pipes[i])
        {
            while (--i >= 0)
                free(pipes[i]);
            return(free(pipes), NULL);
        }
        if (pipe(pipes[i]) < 0)
        {
            perror("pipe");
            while (--i >= 0)
                free(pipes[i]);
            free(pipes);
            return(NULL);
        }
        i++;
    }
    return (pipes);
}

void    close_pipes(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < pipex->count_cmd - 1)
    {
        close(pipex->pipes_fd[i][0]);
        close(pipex->pipes_fd[i][1]);
        free(pipex->pipes_fd[i]);
        i++;
    }
    free(pipex->pipes_fd);
}
