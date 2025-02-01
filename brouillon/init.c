/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:12:22 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/31 13:21:09 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
    if (argc < 5)
    {
        ft_putstr_fd("Not enough arguments\n", 2);
        exit(1);
    }
    pipex->infile = argv[1]; /* infile sera toujours argv[1] */
    pipex->outfile = argv[argc - 1]; /* outfile sera toujours l'avant dernier */
    pipex->inf_fd = -1; /* indiquer qu'aucun fichier n'est encore ouvert */
    pipex->out_fd = -1; /* ou pas encore assigné */
    pipex->pipe_fd = NULL;
    pipex->cmd_count = 0;
    pipex->cmd = NULL;
    pipex->pids = malloc(sizeof(pid_t) * pipex->cmd_count);
    pipex->envp = envp;
    pipex->path = NULL;
}

int open_files(t_pipex *pipex)
{
    pipex->inf_fd = open(pipex->infile, O_RDONLY); /* ouverture du infile en lecture seule */
    if (pipex->inf_fd < 0)
        return (ft_putstr_fd("Unable to open the infile\n", 2), FAIL);
    pipex->out_fd = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644); /* creer, écrire l'outfile */
    if (pipex->out_fd < 0)
        return (ft_putstr_fd("Unable to open/create the outfile\n", 2), FAIL);
    return (SUCCESS);
}
int create_pipes(t_pipex *pipex)
{
    int i;
    
    i = 0;
    pipex->pipe_fd = malloc(sizeof(int *) * (pipex->cmd_count - 1)); /* allouer de la memoire pour tout les pipes */
    if (!pipex->pipe_fd)
        return (ft_putstr_fd("Memory allocation failed\n", 2), FAIL);
    while (i < pipex->cmd_count - 1)
    {
        pipex->pipe_fd[i] = malloc(sizeof(int) * 2); /* x2 pcq chaque pipe a 2 fd : read & write */
        if (!pipex->pipe_fd[i])
        {
            close_pipes(pipex, i);
            return (ft_putstr_fd("Memory allocation failed\n", 2), FAIL);
        }
        if (pipe(pipex->pipe_fd[i]) == -1) /* creation d'un pipe */
        {
            close_pipes(pipex, i + 1);
            return (ft_putstr_fd("Failed to create pipe\n", 2), FAIL);
        }
        i++;
    }
    return (SUCCESS);
}
