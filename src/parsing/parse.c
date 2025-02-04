/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:41:58 by lolq              #+#    #+#             */
/*   Updated: 2025/02/04 09:41:32 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Check if there is enough args and if the 1st arg is "here_doc".
 * The program will work differently according to the 1st arg.
 * Will seach for the commands in the PATH and store them in the structure.
 * Handle the files (infile & outfile).
 */
bool    ft_parse_args(t_pipex *pipex, int ac, char **av)
{
    if (ac < 5)
        return (ft_putstr_fd("Error: Not enough arguments\n", 2), false);
    if (ft_strncmp(av[1], "here_doc", 8) == 0 && ft_strlen(av[1]) == 8)
    {
        pipex->here_doc = true;
        pipex->count_cmd--;
        if (ac < 6)
            return (ft_putstr_fd("Error: Not enough arguments\n", 2), false);
    }
    pipex->cmd = cmd_list(av, 2, ac - 1);
    if (pipex->cmd == NULL)
        return (false);
    return (true);
}

char    *search_path(char **paths, char *cmd)
{
    char    *full_path;
    char    *tmp;
    int     i;

    i = 0;
    while (paths && paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        if (!tmp)
            return (NULL);
        full_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (!full_path)
            return (NULL);
        if (access(full_path, X_OK) == 0)
            return (full_path);
        free(full_path);
        i++;
    }
    return (NULL);
}

char    *find_executable(char *cmd, char **envp)
{
    char    *exec_path;
    char    **paths;
    int     i;

    if (!cmd || cmd[0] == '\0')
        return (NULL);
    i = 0;
    while (envp && envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            paths = ft_split(envp[i] + 5, ':');
            if (!paths)
                return (ft_putstr_fd("Error: PATH not found\n", 2), NULL);
            exec_path = search_path(paths, cmd);
            free_tab(paths);
            return (exec_path);
        }
        i++;
    }
    return (NULL);
}
bool    add_paths(t_pipex *pipex, char **envp)
{
    t_cmd   *tmp;
    int     i;

    i = 0;
    tmp = pipex->cmd;
    pipex->path = malloc(sizeof(char *)*(pipex->count_cmd + 1));
    if (!pipex->path)
        return (false);
    while (i < pipex->count_cmd && tmp)
    {
        pipex->path[i] = find_executable(tmp->cmd[0], envp);
        if (!pipex->path[i])
        {
            ft_putstr_fd("Error: Command not found\n", 2);
            while (--i >= 0)
                free(pipex->path[i]);
            free(pipex->path);
            pipex->path = NULL;
            return (false);
        }
        i++;
        tmp = tmp->next;
    }
    pipex->path[i] = NULL;
    return (true);
}

int open_files(t_pipex *pipex)
{
    pipex->in_fd = open(pipex->infile, O_RDONLY);
    if (pipex->in_fd < 0)
        return(ft_putstr_fd("Error: impossible to open the infile\n", 2), 1);
    pipex->out_fd = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (pipex->out_fd < 0)
        return (ft_putstr_fd("Error: impossible to open or create the outfile\n", 2), 1);
    return (0);
}
