/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:09:29 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/11 10:31:06 by loribeir         ###   ########.fr       */
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

typedef struct t_cmd
{
	char			**cmd;
	struct t_cmd	*next;
}	t_cmd;

typedef struct t_pipex
{
	char	*infile;
	int		in_fd;
	char	*outfile;
	int		out_fd;
	t_cmd	*cmd;
	int		count_cmd;
	int		**pipes_fd;
	pid_t	*pids;
	char	**path;
	bool	here_doc;
}	t_pipex;

/* INIT */
int		ft_init_pipex(t_pipex *pipex, int ac, char **av);
t_cmd	*cmd_list(char **av, int start, int end);
t_cmd	*create_cmd(char *cmd);
void	add_cmd(t_cmd **head, t_cmd *new_cmd);

/* PARSING */
bool	ft_parse_args(t_pipex *pipex, int ac, char **av);
char	*get_path(char **paths, char *cmd);
char	*find_exec(char *cmd, char **envp);
int		open_files(t_pipex *pipex, bool is_output, int fd);
int		handle_here_doc(char *limiter);

/* EXECUTION */
int		ft_execute(t_pipex *pipex, char **envp);
int		handle_fork(t_pipex *pipex, char **envp, int i, t_cmd *current);
int		init_pipes(int **pipes, int i, int max);
int		**create_pipes(t_pipex *pipex);
void	close_all_pipes(t_pipex *pipex);

//
void	first_child(t_pipex *pipex, int i);
void	inter_child(t_pipex *pipex, int i);
void	child_process(t_pipex *pipex, char **envp, int i, t_cmd *current);
void	execute_cmd(t_pipex *pipex, t_cmd *cmd, char **envp, int i);
int		wait_children(t_pipex *pipex);

/* UTILS */
void	free_tab(char **tab);
void	free_cmd_list(t_cmd *head);
void	ft_cleanup(t_pipex *pipex);

#endif