/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:36:19 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/07 10:38:00 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *pipex, char **envp, int i, t_cmd *current)
{
	int	fd;

	fd = -1;
	close_all_pipes_except_current(pipex, i);
	if (i == 0)
	{
		fd = open_files(pipex, false);
		dup2(pipex->in_fd, STDIN_FILENO);
		dup2(pipex->pipes_fd[i][1], STDOUT_FILENO);
	}
	else if (i == pipex->count_cmd - 1)
	{
		fd = open_files(pipex, true);
		dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO);
		dup2(pipex->out_fd, STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO);
		dup2(pipex->pipes_fd[i][1], STDOUT_FILENO);
	}
	if (fd != -1)
		close(fd);
	close_all_pipes(pipex);
	execute_cmd(pipex, current, envp, i);
}

void	execute_cmd(t_pipex *pipex, t_cmd *current, char **envp, int i)
{
	char	*path;

	(void)i;
	(void)pipex;
	path = find_executable(current->cmd[0], envp);
	if (!path)
	{
		ft_cleanup(pipex);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	if (pipex->out_fd != -1)
	{
		execve(path, current->cmd, envp);
		perror("execve");
	}
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

void	close_all_pipes_except_current(t_pipex *pipex, int i)
{
	int	j;

	j = 0;
	while (j < pipex->count_cmd - 1)
	{
		if (j != i)
			close(pipex->pipes_fd[j][1]);
		if (j != i - 1)
			close(pipex->pipes_fd[j][0]);
		j++;
	}
	if (i != 0)
	{
		if (pipex->in_fd > 0)
			close(pipex->in_fd);
	}
	if (i != pipex->count_cmd - 1)
	{
		if (pipex->out_fd > 0)
			close(pipex->out_fd);
	}
}
