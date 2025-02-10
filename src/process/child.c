/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:36:19 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/10 10:09:45 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *pipex, char **envp, int i, t_cmd *current)
{
	if (i == 0)
	{
		open_files(pipex, false);
		dup2(pipex->in_fd, STDIN_FILENO);
		dup2(pipex->pipes_fd[i][1], STDOUT_FILENO);
		close(pipex->in_fd);
		close(pipex->pipes_fd[i][1]);
	}
	else if (i == pipex->count_cmd - 1)
	{
		open_files(pipex, true);
		dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO);
		dup2(pipex->out_fd, STDOUT_FILENO);
		close(pipex->pipes_fd[i - 1][0]);
		close(pipex->out_fd);
	}
	else
	{
		dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO);
		dup2(pipex->pipes_fd[i][1], STDOUT_FILENO);
		close(pipex->pipes_fd[i - 1][0]);
		close(pipex->pipes_fd[i][1]);
	}
	close_all_pipes(pipex);
	execute_cmd(pipex, current, envp, i);
}

void	execute_cmd(t_pipex *pipex, t_cmd *current, char **envp, int i)
{
	char	*path;

	(void)i;
	path = find_exec(current->cmd[0], envp);
	if (!path)
	{
		ft_cleanup(pipex);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	execve(path, current->cmd, envp);
	perror("execve");
	free(path);
	ft_cleanup(pipex);
	exit(EXIT_FAILURE);
}

int	wait_children(t_pipex *pipex)
{
	int	last_status;
	int	status;
	int	i;

	i = 0;
	while (i < pipex->count_cmd)
	{
		if (waitpid(pipex->pids[i], &status, 0) == -1)
		{
			perror("waitpid failed\n");
			continue ;
		}
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		i++;
	}
	return (last_status);
}
