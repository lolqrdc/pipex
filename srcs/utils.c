/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:37:05 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/30 18:28:10 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Parcourt les chemins PATH et verifie l'existence de l'executable */
char    *find_path(t_pipex *pipex, char *cmd)
{
    char    *full_path;
    char    *tmp;
    int     i;
    
    i = 0;
    while (pipex->path && pipex->path[i])
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

    if (!pipex->path) /* init pipex->path */
    {
        i = 0;
        while (pipex->envp && pipex->envp[i])
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
    while (i < count)
    {
        if (pipex->pipe_fd[i])
        {
            close(pipex->pipe_fd[i][0]);
            close(pipex->pipe_fd[i][1]);
            free(pipex->pipe_fd[i]);
        }
        i++;
    }
    free(pipex->pipe_fd);
    pipex->pipe_fd = NULL;
}
