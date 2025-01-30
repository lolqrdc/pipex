/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:57:41 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/30 18:28:12 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
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

/* DEFINE */
#define SUCCESS 0
#define FAIL    1

/* liste chaînée de commandes permet de gérer facilement plusieurs commandes.*/
typedef struct t_cmd
{
    char            **cmds; /* stock chaque commande + ses args */
    struct t_cmd    *next;
} t_cmd;

typedef struct s_pipex
{
    char    *infile;
    char    *outfile;
    int     inf_fd; /* descripteur du infile */
    int     out_fd; /* descripteur du outfile */
    pid_t   *pids; /* stock les PIDs des child processus */
    int     **pipe_fd; /* gerer plusieurs pipes */
    t_cmd   *cmd;
    int     cmd_count;
    char    **envp;
    char    **path;
} t_pipex;

/* FUNCTIONS */
int     parse_args(int ac, char **av, t_pipex *pipex);
int     add_cmd(t_pipex *pipex, char **cmd);
//
int     create_processes(t_pipex *pipex);
void    exec_cmd(t_pipex *pipex, t_cmd *cmd, int index);
//
void    init_pipex(int argc, char **argv, t_pipex *pipex);
int     open_files(t_pipex *pipex);
int     create_pipes(t_pipex *pipex);
//
char    *find_exec(t_pipex *pipex, char *cmd);
char    *find_path(t_pipex *pipex, char *cmd);
void    close_pipes(t_pipex *pipex, int count);
void    free_pipex(t_pipex *pipex);

# endif