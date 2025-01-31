/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:57:18 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/31 10:03:05 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    t_pipex *pipex;
    int     i;

    i = -1;
    pipex = malloc(sizeof(t_pipex));
    init_pipex(argc, argv, pipex);
    if (parse_args(argc, argv, pipex) != 0)
        return (FAIL);
    if (create_pipes(pipex) == FAIL)
        return(FAIL);
    if (create_processes(pipex) == FAIL)
        return (FAIL);
    while (++i < pipex->cmd_count)
        waitpid(pipex->pids[i], NULL, 0);
    close_pipes(pipex, pipex->cmd_count);
    return (0);
}