/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:42:34 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/04 16:24:11 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# ifndef FD_SIZE
#  define FD_SIZE 100
# endif 

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_gnlchr(char *stocker);
char	*ft_gnljoin(char *newline, char *stocker);
char	*ft_gnlclean(char *stocker);
size_t	ft_gnllen(char *str);

#endif