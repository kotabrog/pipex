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

static int	status_cmd_init(t_cmd ***cmd, int argc, char **argv)
{
	int	i;

	i = 0;
	if (ft_malloc(cmd, sizeof(t_cmd *), argc - 2))
		return (ERROR);
	while (i < argc - 3)
	{
		if (cmd_init(&(argv[i + 2]), &((*cmd)[i])))
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
	if (ft_malloc(status, sizeof(t_status), 1))
		return (ERROR);
	(*status)->file1 = argv[1];
	(*status)->file2 = argv[argc - 1];
	(*status)->env = *env;
	if (status_cmd_init(&((*status)->cmd), argc, argv))
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
