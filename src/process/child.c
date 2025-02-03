/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:36:19 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/03 17:29:26 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    child_process(t_pipex *pipex, char **envp, int i)
{
    if (i == 0) // first processus
    {
        dup2(pipex->in_fd, STDIN_FILENO);
        dup2(pipex->pipes_fd[i][1], STDOUT_FILENO);
    }
    else if (i == pipex->count_cmd - 1) // last processus
    {
        dup2(pipex->pipes_fd[i-1][0], STDIN_FILENO);
        dup2(pipex->out_fd, STDOUT_FILENO);
    }
    else // inter processus
    {
        dup2(pipex->pipes_fd[i-1][0], STDIN_FILENO);
        dup2(pipex->pipes_fd[i][1], STDOUT_FILENO);
    }
    close_all_pipes(pipex);
    execute_cmd(pipex, pipex->cmd, envp, i);
}
void    execute_cmd(t_pipex *pipex, t_cmd *cmd, char **envp, int i)
{
    char    *path;

    (void)i;
    (void)pipex;
    path = find_executable(cmd->cmd[0], envp);
    if (!path)
        exit(EXIT_FAILURE);
    execve(path, cmd->cmd, envp);
    perror("execve");
    exit(EXIT_FAILURE);
}
int    wait_children(t_pipex *pipex)
{
    int last_status;
    int status;
    int i;

    i = 0;
    while (i < pipex->count_cmd)
    {
        printf("%d\n", i);
        if (waitpid(pipex->pids[i], &status, 0) == -1)
        {
            perror("waitpid failed\n");
            continue;
        }
        if (WIFEXITED(status))
            last_status = WEXITSTATUS(status);
        i++;
    }
    return (last_status);
}

void    close_all_pipes(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < pipex->count_cmd - 1)
    {
        close(pipex->pipes_fd[i][0]);
        close(pipex->pipes_fd[i][1]);
        i++;
    }
}
