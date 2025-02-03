/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:32:29 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/03 18:23:31 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Useful functions to make pipex work (free).
 * free_tab, free_cmd, cleanup pipex.
 */

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
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

void    ft_cleanup(t_pipex *pipex)
{
    int i;

    i = 0;
    if (pipex == NULL)
        return ;
    if (pipex->pipes_fd != NULL)
        close_all_pipes(pipex);
    free(pipex->pids);
    free(pipex);
}
