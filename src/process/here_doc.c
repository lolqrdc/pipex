/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:09:54 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/07 08:02:28 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_here_doc(char *limiter)
{
	char	*limit_with_nl;
	char	*line;
	int		fd;

	limit_with_nl = ft_strjoin(limiter, "\n");
	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!limit_with_nl || fd < 0)
		return (1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line
			|| ft_strncmp(line, limit_with_nl, ft_strlen(limit_with_nl)) == 0)
		{
			free(line);
			free(limit_with_nl);
			close (fd);
			return (0);
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(limit_with_nl);
	return (close(fd));
}
