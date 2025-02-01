/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:45:02 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/01 14:55:38 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Initialization of the structure */
void    ft_init_pipex(t_pipex *pipex, int ac, char **av)
{
    pipex->infile = av[1];
    pipex->in_fd = -1;
    pipex->outfile = av[ac - 1];
    pipex->out_fd = -1;
    pipex->pipes_fd = NULL;
    pipex->cmd = NULL;
    pipex->count_cmd = 0;
    pipex->pids = NULL;
    pipex->path = NULL;
    pipex->here_doc = false;    
}
/* Check if there is a here_doc */
bool ft_check_args(t_pipex *pipex, int ac, char **av)
{
    if (av[1] && ft_strncmp(av[1], "here_doc", 8) == 0
        && ft_strlen(av[1]) == 8)
        pipex->here_doc = true;
    if (ac < 5 + pipex->here_doc)
        return(ft_putstr_fd("Error: not enough arguments.\n", 2), 0);
    pipex->infile = av[1 + pipex->here_doc];
    pipex->out_fd = av[ac - 1];
    pipex->count_cmd = ac - 3 - pipex->here_doc;
    return (true);
}
/* Open the necessary files */
int ft_open_files(t_pipex *pipex)
{
    if (pipex->here_doc)
    {

    }
    else
    {
        pipex->in_fd = open(pipex->infile, O_RDONLY);
        if (pipex->in_fd == -1)
            return (ft_putstr_fd("Error: failed to open the input file.\n", 2), 1);
    }
    pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex->out_fd == -1)
        return (ft_putstr_fd("Error: failed to open/create the output file.\n", 2), 1);
    return (0);
}

