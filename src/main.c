/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:44 by lolq              #+#    #+#             */
/*   Updated: 2025/02/02 23:12:35 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex;

    pipex = malloc(sizeof(t_pipex));
    ft_init_pipex(pipex, argc, argv);
    if (!ft_parse_args(pipex, argc, argv))
        return (1);
    if (!add_paths(pipex, envp))
        return (1);
    return (0);
}
