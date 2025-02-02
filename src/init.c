/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:41:06 by lolq              #+#    #+#             */
/*   Updated: 2025/02/02 23:05:55 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Initialize the structure t_pipex with default values.
 * The function cmd_list is called to create a linked list of commands.
 * Create_cmd and add_cmd are used to create and add a new command to the list.
 */

int ft_init_pipex(t_pipex *pipex, int ac, char **av)
{
    pipex->infile = av[1];
    pipex->outfile = av[ac - 1];
    pipex->in_fd = -1;
    pipex->out_fd = -1;
    pipex->count_cmd = ac - 3;
    pipex->cmd = NULL;
    if (pipex->cmd == NULL)
        return (1);
    pipex->pipes_fd = NULL;
    pipex->pids = NULL;
    pipex->path = NULL;
    pipex->here_doc = false;
    return (0);
}

t_cmd   *cmd_list(char **av, int start, int end)
{
    t_cmd   *new_cmd;
    t_cmd   *head;
    int     i;

    head = NULL;
    i = start;
    while (i < end)
    {
        new_cmd = create_cmd(av[i]);
        if (new_cmd == NULL)
        {
            free_cmd_list(head);
            return (NULL);
        }
        i++;
        add_cmd(&head, new_cmd);
    }
    return (head);
}

t_cmd   *create_cmd(char *cmd)
{
    t_cmd   *new_cmd;
    
    new_cmd = malloc(sizeof(t_cmd));
    if (new_cmd == NULL)
        return (NULL);
    new_cmd->cmd = ft_split(cmd, ' ');
    new_cmd->next = NULL;
    return (new_cmd);
}

void    add_cmd(t_cmd **head, t_cmd *new_cmd)
{
    t_cmd   *tmp;

    if (*head == NULL)
    {
        *head = new_cmd;
        return ;
    }
    tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_cmd;
}

void    free_cmd_list(t_cmd *head)
{
    t_cmd   *tmp;
    int     i;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        i = 0;
        while (tmp->cmd[i] != NULL)
        {
            free(tmp->cmd[i]);
            i++;
        }
        free(tmp->cmd);
        free(tmp);
    }
}
