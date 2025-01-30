/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:35:21 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/30 17:30:01 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Créer autant de child processus que de cmd à exec */
int     create_processes(t_pipex *pipex)
{
    t_cmd   *current_cmd;
    int     i;

    i = 0;
    current_cmd = pipex->cmd;
    while (i < pipex->cmd_count)
    {
        pipex->pids[i] = fork();
        if (pipex->pids[i] == -1)
        {
            perror("Fork failed\n");
            return (FAIL);
        }
        if (pipex->pids[i] == 0) /* entrer dans le processus enfant */
        {
            exec_cmd(pipex, current_cmd, i);
            exit(127);
        }
        current_cmd = current_cmd->next; /* passage a la cmd suivante pour le parent */
    }
    return (SUCCESS);
}
void    exec_cmd(t_pipex *pipex, t_cmd *cmd, int index)
{
    char    *exec_path;

    if (index == 0)
        dup2(pipex->inf_fd, STDIN_FILENO); /* 1er cmd : entree depuis infile */
    else
        dup2(pipex->pipe_fd[index - 1][0], STDIN_FILENO); /* autre cmd : entrée depuis le pipe d'avant */
    if (index == pipex->cmd_count - 1)
        dup2(pipex->out_fd, STDOUT_FILENO); /* last cmd : sortie vers outfile */
    else
        dup2(pipex->pipe_fd[index][1], STDOUT_FILENO); /* autre cmd : sortie vers le pipe suivant */
    close_pipes(pipex); /* fermer les pipes non utilisés */
    exec_path = find_exec(pipex, cmd->cmds[0]); /* recherche du path de la cmd */
    if (!exec_path)
    {
        ft_putstr_fd(cmd->cmds[0], 2);
        ft_putstr_fd("Command not found.\n", 2);
        exit(127);
    }
    execve(exec_path, cmd->cmds, pipex->envp); /* execution de la commande */
    perror(cmd->cmds[0]);
    free(exec_path);
    exit(127);
}

