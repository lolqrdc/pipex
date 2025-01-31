/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:57:41 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/31 11:48:26 by loribeir         ###   ########.fr       */
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

/* liste chaînée pour l'environnement permet de facilement copier, parcourir l'ensemble des variable d'envp */
typedef struct t_envp
{
    char            *path;
    struct t_envp   *next;   
} t_envp;
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
    t_envp  *envp;
} t_pipex;

/* MAIN */
int main(int argc, char **argv);

/* PARSING */
int     parse_args(int ac, char **av, t_pipex *pipex);
int     add_cmd(t_pipex *pipex, char **cmd);

/* ENVP */
int     count_envp(t_envp *envp);
char    **convert_envp(t_envp *envp_list);
void    add_envp(t_pipex *pipex, const char *envp);
void    free_envp(t_envp *envp);

/* EXEC */
int     create_processes(t_pipex *pipex);
void    exec_cmd(t_pipex *pipex, t_cmd *cmd, int index);
char    *find_exec(t_pipex *pipex, char *cmd);
char    *find_path(t_pipex *pipex, char *cmd);
void    close_pipes(t_pipex *pipex, int count);

/* INIT */
void    init_pipex(int argc, char **argv, t_pipex *pipex);
int     open_files(t_pipex *pipex);
int     create_pipes(t_pipex *pipex);

# endif