/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:44 by lolq              #+#    #+#             */
/*   Updated: 2025/02/05 14:07:46 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex;
    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        return (1);
    if (ft_init_pipex(pipex, argc, argv) != 0)
        return (ft_cleanup(pipex), 1);
    if (!ft_parse_args(pipex, argc, argv))
        return (ft_cleanup(pipex), 1);
    if (!add_paths(pipex, envp))
        return (ft_cleanup(pipex), 1);
    if (open_files(pipex) != 0)
        return (ft_cleanup(pipex), 1);
    ft_execute(pipex, envp);
    ft_cleanup(pipex);
    return (0);
}
