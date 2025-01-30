/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:42:18 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/03 13:05:46 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stocker [FD_SIZE][BUFFER_SIZE + 1] = {};
	char		*newline;
	int			to_read;

	newline = NULL;
	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_gnlchr(stocker[fd]))
		(ft_gnlclean(stocker[fd]), newline = ft_gnljoin(newline, stocker[fd]));
	to_read = 1;
	while (to_read > 0 && ft_gnlchr(stocker[fd]) == 0)
	{
		to_read = read(fd, stocker[fd], BUFFER_SIZE);
		if (to_read < 0)
			return (free(newline), NULL);
		if (to_read == 0)
		{
			if (newline != NULL && newline[0] != '\0')
				return (newline);
			return (free(newline), NULL);
		}
		stocker[fd][to_read] = '\0';
		newline = ft_gnljoin(newline, stocker[fd]);
	}
	return (newline);
}
/*int main (void)
{
	char	*line1;
	char	*line2;
	int		fd1;
	int		fd2;
	int		i;
	
	fd1 = open("test07.txt", O_RDONLY);
	fd2 = open("test08.txt", O_RDONLY);

	i = 0;
	while (i < 10)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line1)
		{
			printf("fichier 1 : %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("fichier 2 : %s", line2);
			free(line2);
		}
		if (!line1 && !line2)
			break;
	}
	close(fd1);
	close(fd2);
	return (0);
}*/