/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:57:18 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/30 11:41:56 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    t_pipex *pipex;

    init_pipex(argc, **argv, pipex);
    if (parse_args(argc, argv, pipex) != 0)
        return (FAIL);
}