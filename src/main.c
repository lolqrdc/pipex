/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:44 by lolq              #+#    #+#             */
/*   Updated: 2025/02/10 10:52:47 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		exit_code;

	if (argc < 5)
		return (ft_putstr_fd("Error: Not enough arguments\n", 2), 1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	if (ft_init_pipex(pipex, argc, argv) != 0)
		return (ft_cleanup(pipex), 1);
	if (!ft_parse_args(pipex, argc, argv))
		return (ft_cleanup(pipex), 1);
	exit_code = ft_execute(pipex, envp);
	ft_cleanup(pipex);
	exit(exit_code);
}
