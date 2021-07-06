/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:36:27 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/07 00:31:16 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_init(char **argv, t_cmd **cmd)
{
	if (ft_malloc(cmd, sizeof(t_cmd), 1))
		return (ERROR);
	(*cmd)->cmd = *argv;
	(*cmd)->pipefd[0] = -1;
	(*cmd)->pipefd[1] = -1;
	(*cmd)->fd = -1;
	return (SUCCESS);
}

int	cmd_free(t_cmd ***cmd)
{
	t_cmd	**temp;

	temp = *cmd;
	while (*temp)
		free(*(temp++));
	ft_free(cmd);
	return (SUCCESS);
}
