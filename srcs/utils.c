/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:37:05 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/30 12:06:10 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    close_pipes(t_pipex *pipex)
{

}

void    free_pipes(t_pipex *pipex, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        free(pipex->pipe_fd[i]);
        i++;
    }
    free(pipex->pipe_fd);
    pipex->pipe_fd = NULL;
}
void    free_pipex(t_pipex *pipex)
{
    
}