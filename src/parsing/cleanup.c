/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:32:29 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/11 09:31:44 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_cmd_list(t_cmd *head)
{
	t_cmd	*current;
	t_cmd	*next;
	int		i;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		if (current->cmd)
		{
			i = 0;
			while (current->cmd[i])
			{
				free(current->cmd[i]);
				i++;
			}
			free(current->cmd);
			current->cmd = NULL;
		}
		free(current);
		current = next;
	}
}

void	ft_cleanup(t_pipex *pipex)
{
	if (pipex == NULL)
		return ;
	if (pipex->path)
	{
		free_tab(pipex->path);
		pipex->path = NULL;
	}
	if (pipex->cmd)
	{
		free_cmd_list(pipex->cmd);
		pipex->cmd = NULL;
	}
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
	if (pipex->pids)
	{
		free(pipex->pids);
		pipex->pids = NULL;
	}
	if (pipex->here_doc == true)
		unlink("here_doc");
	free(pipex);
}
