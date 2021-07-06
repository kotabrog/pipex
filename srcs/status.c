/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:07:53 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/07 00:29:42 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	status_cmd_init(t_cmd ***cmd, int argc, char **argv, int flag)
{
	int	i;

	i = 0;
	if (ft_malloc(cmd, sizeof(t_cmd *), argc - 2 - flag))
		return (ERROR);
	while (i < argc - 3 - flag)
	{
		if (cmd_init(&(argv[i + flag + 2]), &((*cmd)[i])))
		{
			cmd_free(cmd);
			return (ERROR);
		}
		++i;
	}
	(*cmd)[i] = NULL;
	return (SUCCESS);
}

int	status_init(int argc, char **argv, char ***env, t_status **status)
{
	int	flag;

	flag = FALSE;
	if (ft_malloc(status, sizeof(t_status), 1))
		return (ERROR);
	(*status)->heredoc_flag = FALSE;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		flag = TRUE;
		(*status)->heredoc_flag = TRUE;
	}
	(*status)->file1 = argv[1 + flag];
	(*status)->file2 = argv[argc - 1];
	(*status)->env = *env;
	if (status_cmd_init(&((*status)->cmd), argc, argv, flag))
	{
		free(status);
		return (ERROR);
	}
	return (SUCCESS);
}

int	status_free(t_status *status)
{
	cmd_free(&(status->cmd));
	free(status);
	return (SUCCESS);
}
