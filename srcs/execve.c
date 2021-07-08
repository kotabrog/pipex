/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:24:18 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/08 18:47:15 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process_command(t_status *status, t_cmd *cmd, t_cmd *next_cmd)
{
	char	**arg;
	int		flag;

	flag = SUCCESS;
	arg = ft_split(cmd->cmd, ' ');
	if (arg == NULL)
		flag = ERROR;
	if (!flag && status->cmd[0] == cmd)
		flag = SUCCESS;
	else if (!flag && cmd->pipefd[READ] != -1 && \
				dup2(cmd->pipefd[READ], READ) == -1)
		flag = ERROR;
	if (!flag && next_cmd == NULL)
		flag = SUCCESS;
	else if (!flag && cmd->pipefd[WRITE] != -1 && \
				dup2(cmd->pipefd[WRITE], WRITE) == -1)
		flag = ERROR;
	multi_close(&(cmd->pipefd[READ]), &(cmd->pipefd[WRITE]), NULL, NULL);
	if (!flag)
		execve(arg[0], arg, status->env);
	exit(EXIT_FAILURE);
}
