/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:22:15 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/31 12:01:54 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int count_envp(t_envp *envp)
{
    int count;

    count = 0;
    while (envp)
    {
        count++;
        envp = envp->next;
    }
    return (count);    
}

char    **convert_envp(t_envp *envp_list)
{
    int     i;
    int     count;
    char    **envp;

    envp = malloc((count + 1) * sizeof(char *));
    i = 0;
    count = count_envp(envp_list);
    if (!envp)
        return (NULL);
    while (envp_list)
    {
        envp[i] = ft_strdup(envp_list->path);
        envp_list = envp_list->next;
        i++;
    }
    envp[i] = NULL;
    return (envp);
}

void    add_envp(t_pipex *pipex, const char *envp)
{
    t_envp  *new_node;

    new_node = malloc(sizeof(t_envp));
    if (!new_node)
        return ;
    new_node->path = ft_strdup(envp);
    new_node->next = pipex->envp;
    pipex->envp = new_node;
}
void    free_envp(t_envp *envp)
{
    t_envp  *tmp;

    while (envp)
    {
        tmp = envp;
        envp = envp->next;
        free(tmp->path);
        free(tmp);
    }
}
