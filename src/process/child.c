/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:36:19 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/11 10:44:00 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pipex, int i)
{
	if (open_files(pipex, false, 0) == -1)
	{
		perror("infile");
		close_all_pipes(pipex);
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->in_fd, STDIN_FILENO) == -1
		|| dup2(pipex->pipes_fd[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close_all_pipes(pipex);
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	close(pipex->in_fd);
	close(pipex->pipes_fd[i][1]);
}
void	inter_child(t_pipex *pipex, int i)
{
	if (open_files(pipex, true, 0) == -1)
	{
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO);
	dup2(pipex->out_fd, STDOUT_FILENO);
	if (dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close_all_pipes(pipex);
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	close(pipex->pipes_fd[i - 1][0]);
	close(pipex->out_fd);
}
void	child_process(t_pipex *pipex, char **envp, int i, t_cmd *current)
{
	if (i == 0)
		first_child(pipex, i);
	else if (i == pipex->count_cmd - 1)
		inter_child(pipex, i);
	else
	{
		dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO);
		dup2(pipex->pipes_fd[i][1], STDOUT_FILENO);
		if (dup2(pipex->pipes_fd[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close_all_pipes(pipex);
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
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
