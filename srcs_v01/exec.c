/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:35:21 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/31 13:58:54 by loribeir         ###   ########.fr       */
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
        else
        {
            if (i > 0)
                close(pipex->pipe_fd[i-1][0]);
            if (i < pipex->cmd_count - 1)
                close(pipex->pipe_fd[i][1]);
        }
        current_cmd = current_cmd->next; /* passage a la cmd suivante pour le parent */
        i++;
    }
    return (SUCCESS);
}
void    exec_cmd(t_pipex *pipex, t_cmd *cmd, int index)
{
    char    *exec_path;

    close(pipex->inf_fd);
    close(pipex->out_fd);
    if (index == 0)
        dup2(pipex->inf_fd, STDIN_FILENO); /* 1er cmd : entree depuis infile */
    else
        dup2(pipex->pipe_fd[index - 1][0], STDIN_FILENO); /* autre cmd : entrée depuis le pipe d'avant */
    if (index == pipex->cmd_count - 1)
        dup2(pipex->out_fd, STDOUT_FILENO); /* last cmd : sortie vers outfile */
    else
        dup2(pipex->pipe_fd[index][1], STDOUT_FILENO); /* autre cmd : sortie vers le pipe suivant */
    close_pipes(pipex, index); /* fermer les pipes non utilisés */
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

/* Parcourt les chemins PATH et verifie l'existence de l'executable */
char    *find_path(t_pipex *pipex, char *cmd)
{
    char    *full_path;
    char    *tmp;
    int     i;
    
    if (!pipex->path)
        return (NULL);
    i = 0;
    while (pipex->path[i])
    {
        tmp = ft_strjoin(pipex->path[i], "/"); /* build le chemin complet */
        if (!tmp)
            return (NULL);
        full_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (!full_path)
            return (NULL);
        if (access(full_path, X_OK) == 0) /* verifier si le fichier existe + executable */
            return (full_path);
        free(full_path); /* free le chemin si pas valide */
        i++;
    }
    return (NULL);
}
char    *find_exec(t_pipex *pipex, char *cmd)
{
    int i;

    i = 0;
    if (!pipex->path) 
    {
        while (pipex->envp[i])
        {
            if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0) /* search PATH dans l'environnement */
            {
                pipex->path = ft_split(pipex->envp[i] + 5, ':');
                if (!pipex->path)
                    return (NULL); /* si aucun PATH est trouvé */
            }
            i++;
        }
    }
    return (find_path(pipex, cmd)); /* search l'exec dans les chemins du PATH */
}

void    close_pipes(t_pipex *pipex, int count)
{
    int i;

    i = 0;
    while (i < pipex->cmd_count - 1)
    {
        if (i != count - 1)
            close(pipex->pipe_fd[i][1]);
        if (i != count)
            close(pipex->pipe_fd[i][0]);
        i++;
    }
}



