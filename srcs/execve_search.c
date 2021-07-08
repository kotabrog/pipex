/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:01:16 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/08 20:17:11 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_path_value(char **path, char **env)
{
	while (*env)
	{
		if (ft_strncmp("PATH=", *env, 5) == 0)
		{
			*path = *env + 5;
			return (SUCCESS);
		}
		++env;
	}
	return (ERROR);
}

static int	get_path_list(char **join_path, char ***path_list, char **env, \
	char *com)
{
	char	*path;

	*path_list = NULL;
	*join_path = NULL;
	if (get_path_value(&path, env))
		return (ERROR);
	*path_list = ft_split(path, ':');
	if (*path_list == NULL)
		return (ERROR);
	*join_path = ft_strjoin("/", com);
	if (*join_path == NULL)
	{
		ft_free_double_char(path_list);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	path_search_execve(char **com, char **env)
{
	char		*join_path;
	char		**path_list;
	int			flag;
	char		**temp;

	flag = get_path_list(&join_path, &path_list, env, com[0]);
	if (flag)
		return (flag);
	flag = ERROR;
	temp = path_list;
	while (*path_list)
	{
		com[0] = ft_strjoin(*(path_list++), join_path);
		if (!com[0])
			break ;
		execve(com[0], &com[0], env);
		flag = errno;
		free(com[0]);
	}
	free(join_path);
	ft_free_double_char(&temp);
	return (flag);
}

static int	decide_search_or_not(char *com)
{
	while (*com)
	{
		if (*com == '/')
			return (TRUE);
		++com;
	}
	return (FALSE);
}

int	search_execve(char **com, char **env)
{
	int		flag;
	char	*temp;

	temp = com[0];
	if (decide_search_or_not(com[0]))
	{
		execve(com[0], com, env);
		flag = errno;
	}
	else
	{
		flag = path_search_execve(com, env);
		com[0] = temp;
	}
	return (flag);
}
