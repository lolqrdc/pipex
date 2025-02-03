/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:44 by lolq              #+#    #+#             */
/*   Updated: 2025/02/03 14:02:23 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_commands(t_pipex *pipex)
{
    t_cmd *current;
    int cmd_num;

    if (!pipex || !pipex->cmd)
    {
        printf("No commands to display.\n");
        return;
    }

    current = pipex->cmd;
    cmd_num = 1;

    printf("Input file: %s\n", pipex->infile);
    printf("Output file: %s\n", pipex->outfile);
    printf("Number of commands: %d\n", pipex->count_cmd);
    printf("Commands:\n");

    while (current)
    {
        printf("Command %d: ", cmd_num);
        for (int i = 0; current->cmd[i]; i++)
        {
            printf("%s", current->cmd[i]);
            if (current->cmd[i + 1])
                printf(" ");
        }
        printf("\n");
        current = current->next;
        cmd_num++;
    }
}

void print_pipes(t_pipex *pipex)
{
    if (!pipex || !pipex->pipes_fd)
    {
        printf("Aucun pipe à afficher.\n");
        return;
    }

    printf("Pipes :\n");
    for (int i = 0; i < pipex->count_cmd - 1; i++)
    {
        if (pipex->pipes_fd[i])
        {
            printf("Pipe %d : [%d, %d]", i, pipex->pipes_fd[i][0], pipex->pipes_fd[i][1]);
            if (fcntl(pipex->pipes_fd[i][0], F_GETFD) != -1)
                printf(" (lecture ouvert)");
            else
                printf(" (lecture fermé)");
            
            if (fcntl(pipex->pipes_fd[i][1], F_GETFD) != -1)
                printf(" (écriture ouvert)");
            else
                printf(" (écriture fermé)");
            printf("\n");
        }
        else
        {
            printf("Pipe %d : NULL\n", i);
        }
    }
}

int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex;

    pipex = malloc(sizeof(t_pipex));
    ft_init_pipex(pipex, argc, argv);
    if (!ft_parse_args(pipex, argc, argv))
        return (1);
    if (!add_paths(pipex, envp))
        return (1);
    open_files(pipex);
    ft_execute(pipex, envp);
    print_pipes(pipex);
    return (0);
}
