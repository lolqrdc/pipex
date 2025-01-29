/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:57:41 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/29 19:33:43 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* LIBRARIES */
# include "../include/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include <fcntl.h>

/* liste chaînée de commandes permet de gérer facilement plusieurs commandes.*/
typedef struct t_cmd
{
    char            **cmds; /* stock chaque commande + ses args*/
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
}
