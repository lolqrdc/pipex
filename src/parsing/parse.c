/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:41:58 by lolq              #+#    #+#             */
/*   Updated: 2025/02/10 11:20:31 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Check if there is enough args and if the 1st arg is "here_doc".
 * The program will work differently according to the 1st arg.
 * Will seach for the commands in the PATH and store them in the structure.
 * Handle the files (infile & outfile).
 */
bool	ft_parse_args(t_pipex *pipex, int ac, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && ft_strlen(av[1]) == 8)
	{
		pipex->here_doc = true;
		pipex->count_cmd--;
		if (ac < 6)
		{
			ft_putstr_fd("Error: Not enough arguments\n", 2);
			ft_cleanup(pipex);
			exit(EXIT_FAILURE);
		}
		handle_here_doc(av[2]);
		pipex->cmd = cmd_list(av, 3, ac - 1);
	}
	else
		pipex->cmd = cmd_list(av, 2, ac - 1);
	if (pipex->cmd == NULL)
		return (false);
	return (true);
}

char	*get_path(char **paths, char *cmd)
{
	char	*full_path;
	char	*tmp;
	int		i;

	i = 0;
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*find_exec(char *cmd, char **envp)
{
	char	*exec_path;
	char	**paths;
	int		i;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				return (ft_putstr_fd("Error: PATH not found\n", 2), NULL);
			exec_path = get_path(paths, cmd);
			free_tab(paths);
			return (exec_path);
		}
		i++;
	}
	return (NULL);
}

int	open_files(t_pipex *pipex, bool is_output)
{
	int	fd;

	if (is_output)
	{
		fd = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror(pipex->outfile);
			return (1);
		}
		pipex->out_fd = fd;
	}
	else
	{
		fd = open(pipex->infile, O_RDONLY);
		if (fd < 0)
		{
			perror(pipex->infile);
			return (1);
		}
		pipex->in_fd = fd;
	}
	return (0);
}
