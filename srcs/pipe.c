/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:58:26 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/09 00:11:17 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipe_recursive(t_status *status, int cmd_num, int before_fd)
{
	int	pipefd[2];

	pipefd[0] = -1;
	pipefd[1] = -1;
	if (status->cmd[cmd_num + 1] && pipe(pipefd))
		return (ERROR);
	status->cmd[cmd_num]->pipefd[READ] = before_fd;
	status->cmd[cmd_num]->pipefd[WRITE] = pipefd[WRITE];
	status->cmd[cmd_num]->pid = fork();
	if (status->cmd[cmd_num]->pid == -1)
	{
		multi_close(&(pipefd[0]), &(pipefd[1]), NULL, NULL);
		return (ERROR);
	}
	if (status->cmd[cmd_num]->pid == 0)
	{
		ft_close(&(pipefd[READ]));
		process_command(status, status->cmd[cmd_num], \
						status->cmd[cmd_num + 1]);
	}
	multi_close(&(status->cmd[cmd_num]->pipefd[READ]), \
		&(status->cmd[cmd_num]->pipefd[WRITE]), NULL, NULL);
	if (status->cmd[cmd_num + 1])
		return (pipe_recursive(status, cmd_num + 1, pipefd[READ]));
	return (SUCCESS);
}

int	process_pipe(t_status *status)
{
	int	flag;
	int	pid;
	int	wait_status;

	flag = pipe_recursive(status, 0, -1);
	while (TRUE)
	{
		pid = wait(&wait_status);
		if (pid == -1)
			break ;
	}
	return (flag);
}
