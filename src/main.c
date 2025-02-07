/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:44 by lolq              #+#    #+#             */
/*   Updated: 2025/02/07 08:10:18 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (ft_putstr_fd("Error: Not enough arguments\n", 2), 1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	if (ft_init_pipex(pipex, argc, argv) != 0)
		return (ft_cleanup(pipex), 1);
	if (!ft_parse_args(pipex, argc, argv))
		return (ft_cleanup(pipex), 1);
	if (open_files(pipex) != 0)
		return (ft_cleanup(pipex), 1);
	ft_execute(pipex, envp);
	ft_cleanup(pipex);
	return (0);
}
