/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:46:38 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/06 18:21:21 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief 
 */

void    ft_execute(t_pipex *pipex, char **envp)
{
    int     i;
    t_cmd   *current;
    int     exit_code;
    
    i = 0;
    current = pipex->cmd;
    pipex->pipes_fd = create_pipes(pipex);
    if (!pipex->pipes_fd)
        return ;
    while (i < pipex->count_cmd)
    {
        handle_fork(pipex, envp, i, current);
        current = current->next;
        i++;
    }
    close_all_pipes(pipex);
    exit_code = wait_children(pipex); // exit avec un bon code erreur pour que le parent le recupere.
    exit(exit_code);
}
int handle_fork(t_pipex *pipex, char **envp, int i, t_cmd *current)
{
    pipex->pids[i] = fork();
    if (pipex->pids[i] == 0)
    {
        child_process(pipex, envp, i, current);
        exit(EXIT_FAILURE);
    }
    else if (pipex->pids[i] < 0)
    {
        perror("fork");
        return (1);
    }
    return (0);
}

int init_pipes(int **pipes, int i, int max)
{
    if (i >= max)
        return (1);
    pipes[i] = malloc(sizeof(int) * 2);
    if (!pipes[i])
    {
        perror("malloc");
        while (i-- >= 0)
            free(pipes[i]);
        return (0);
    }
    if (pipe(pipes[i]) < 0)
    {
        perror("pipe");
        free(pipes[i]);
        while (i -- >= 0)
            free(pipes[i]);
        return (0);
    }
    return (init_pipes(pipes, i + 1, max));
}

int **create_pipes(t_pipex *pipex)
{
    int **pipes;
    
    pipes = malloc(sizeof(int *) * (pipex->count_cmd - 1));
    if (!pipes)
    {
        perror("malloc");
        return (NULL);
    }
    if (!init_pipes(pipes, 0, pipex->count_cmd - 1))
    {
        free(pipes);
        return (NULL);
    }
    return (pipes);
}

/* Close if error case or end of the program */
void    close_all_pipes(t_pipex *pipex)
{
    int i;
    i = 0;
    if (!pipex || !pipex->pipes_fd)
        return;
        
    while (i < pipex->count_cmd - 1)
    {
        if (pipex->pipes_fd[i])
        {
            close(pipex->pipes_fd[i][0]);
            close(pipex->pipes_fd[i][1]);
            free(pipex->pipes_fd[i]);
            pipex->pipes_fd[i] = NULL;
        }
        i++;
    }
    free(pipex->pipes_fd);
    pipex->pipes_fd = NULL;
}
