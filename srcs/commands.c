/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:32:48 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/30 17:19:46 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Analyser les args de la ligne de commande */
int parse_args(int ac, char **av, t_pipex *pipex)
{
    char    **cmd;
    int     i;

    i = 2;
    while (i < ac - 1) /* s'arrêter a l'avant dernier argument */
    {
       cmd = ft_split(av[i], ' '); /* séparer chaque cmd */
       if (!cmd)
            return (ft_putstr_fd("Memory allocation failed\n", 2), FAIL);
        if (add_cmd(pipex, cmd) != 0)
        {
            free(cmd);
            return (ft_putstr_fd("Failed to add command\n", 2), FAIL);
        }
        i++; 
    }
    return (SUCCESS);
}

/* Ajouter les cmd valide a t_pipex */
int add_cmd(t_pipex *pipex, char **cmd)
{
    t_cmd *last_cmd;   
    t_cmd *new_cmd;

    new_cmd = malloc(sizeof(t_cmd));
    if (!new_cmd)
        return (FAIL);
    new_cmd->cmds = cmd; /* init le nouveau noeud avec la cmd passée en arg */
    new_cmd->next = NULL;
    if (!pipex->cmd) /* if la lst de cmd est vide */
        pipex->cmd = new_cmd; /* le nouveau node devient la 1er cmd */
    else
    {
        last_cmd = pipex->cmd;
        while (last_cmd->next)
            last_cmd = last_cmd->next;
        last_cmd->next = new_cmd; /* add le nouveau node la la fin de la liste */
    }
    pipex->cmd_count++;
    return (SUCCESS);
}
