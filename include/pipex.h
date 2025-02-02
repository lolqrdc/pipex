/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:09:29 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/02 23:23:05 by lolq             ###   ########.fr       */
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
    t_cmd   *cmd;
    int     count_cmd;
    int     **pipes_fd;
    pid_t   *pids;
    char    **path;
    bool     here_doc;
} t_pipex;


/* FUNCTIONS */
int     ft_init_pipex(t_pipex *pipex, int ac, char **av);
t_cmd   *cmd_list(char **av, int start, int end);
t_cmd   *create_cmd(char *cmd);
void    add_cmd(t_cmd **head, t_cmd *new_cmd);
void    free_cmd_list(t_cmd *head);
bool    ft_parse_args(t_pipex *pipex, int ac, char **av);
char    *search_path(char **paths, char *cmd);
char    *find_executable(char *cmd, char **envp);
bool    add_paths(t_pipex *pipex, char **envp);
void    free_tab(char **tab);
#endif