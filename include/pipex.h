/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:09:29 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/01 14:38:22 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

/* LIBRARIES */
# include "../libft/include/libft.h" 
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct t_cmd
{
    char            **cmd;
    struct t_cmd    *next;
} t_cmd;

typedef struct t_pipex
{
    char    *infile; 
    int     in_fd;
    char    *outfile;
    int     out_fd;
    t_cmd   *cmd; /* gerer [x] cmd */
    int     count_cmd; /* nb total de cmd exec dans la pipeline */
    int     **pipes_fd; /* stocker les fd des pipes */
    pid_t   *pids; /* stocker les pids des processus enfant */
    char    *path; /* stocker le path des cmd */
    bool     here_doc;
} t_pipex;

/* FUNCTIONS */
void    ft_init_pipex(t_pipex *pipex, int ac, char **av);


#endif