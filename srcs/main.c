/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:57:18 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/30 18:03:54 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    t_pipex *pipex;
    int     status;
    int     i;

    i = -1;
    init_pipex(argc, **argv, pipex);
    if (parse_args(argc, argv, pipex) != 0)
        return (FAIL);
    if (create_pipes(pipex) == FAIL)
        return(FAIL);
    if (create_processes(pipex) == FAIL)
        return (FAIL);
    while (++i < pipex->cmd_count)
        waitpid(pipex->pids[i], NULL, 0);
    close_pipes(pipex);
    return (0);
}