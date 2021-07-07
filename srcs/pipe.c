/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:58:26 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/08 00:30:05 by ksuzuki          ###   ########.fr       */
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
	if (status->cmd[cmd_num + 1])
		return (pipe_recursive(status, cmd_num + 1, pipefd[READ]));
	return (SUCCESS);
}

static int	pid_search_close(t_cmd **cmd, int pid)
{
	if ((*cmd)->pid == pid)
	{
		(*cmd)->pid = -1;
		multi_close(&((*cmd)->pipefd[WRITE]), &((*(cmd + 1))->pipefd[READ]), \
					NULL, NULL);
		return (SUCCESS);
	}
	while (*(cmd + 1) && (*(cmd + 1))->pid != pid)
		++cmd;
	if (*(cmd + 1) == NULL)
	{
		ft_close(&((*cmd)->pipefd[WRITE]));
		return (SUCCESS);
	}
	multi_close(&((*cmd)->pipefd[WRITE]), &((*(cmd + 1))->pipefd[READ]), \
				&((*(cmd + 1))->pipefd[WRITE]), NULL);
	++cmd;
	(*cmd)->pid = -1;
	if (*(cmd + 1))
		ft_close(&((*(cmd + 1))->pipefd[READ]));
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
		if (pid_search_close(status->cmd, pid))
			flag = ERROR;
	}
	return (flag);
}
