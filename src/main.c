/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:50:27 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/01 14:45:18 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex;
    int     i;

    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        return (EXIT_FAILURE);
    ft_init_pipex(pipex, argc, argv);
}
