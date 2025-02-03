/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:46:38 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/03 18:31:43 by loribeir         ###   ########.fr       */
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
    
    i = 0;
    current = pipex->cmd;
    pipex->pipes_fd = create_pipes(pipex);
    if (!pipex->pipes_fd)
        return ;
    while (i < pipex->count_cmd)
    {
        pipex->cmd = current;
        handle_fork(pipex, envp, i);
        current = current->next;
        i++;
    }
    close_all_pipes(pipex);
    wait_children(pipex);
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

    if (pipex->count_cmd <= 1) {
        fprintf(stderr, "Erreur : Nombre de commandes insuffisant\n");
        return NULL;
    }

    pipes = malloc(sizeof(int *) * (pipex->count_cmd - 1));
    if (!pipes) {
        perror("malloc");
        return NULL;
    }

    for (i = 0; i < pipex->count_cmd - 1; i++) {
        pipes[i] = malloc(sizeof(int) * 2);
        if (!pipes[i]) {
            perror("malloc");
            while (--i >= 0)
                free(pipes[i]);
            free(pipes);
            return NULL;
        }
        if (pipe(pipes[i]) < 0) {
            perror("pipe");
            while (i >= 0) {
                free(pipes[i]);
                i--;
            }
            free(pipes);
            return NULL;
        }
    }
    return pipes;
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
