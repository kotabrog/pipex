/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 00:02:12 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/07 00:31:21 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	debug_status(t_status *status)
{
	t_cmd	**cmd;
	char	**env;

	printf("file1: %s\n", status->file1);
	printf("file2: %s\n", status->file2);
	printf("heredoc_flag: %d\n", status->heredoc_flag);
	cmd = status->cmd;
	env = status->env;
	while (*cmd)
		printf("cmd: %s\n", (*(cmd++))->cmd);
	while (*env)
		printf("env: %s\n", *(env++));
}
