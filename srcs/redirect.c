/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:04:25 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/08 21:42:23 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	redirect_error(char *file)
{
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": could not be opened.", 2);
	return (ERROR);
}

static int	set_file(char *file, int to_fd)
{
	int	fd;
	int	flag;

	flag = SUCCESS;
	fd = -1;
	if (to_fd == READ)
		fd = open(file, O_RDONLY);
	else if (to_fd == WRITE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (to_fd == APPEND)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (redirect_error(file));
	if (dup2(fd, !!to_fd) == -1)
		flag = errno;
	close(fd);
	return (flag);
}

int	redirect(t_status *status, int read_or_write)
{
	if (read_or_write == WRITE && status->heredoc_flag)
		return (set_file(status->file2, APPEND));
	else if (status->heredoc_flag)
		return (SUCCESS);
	else if (read_or_write == WRITE)
		return (set_file(status->file2, WRITE));
	else
		return (set_file(status->file1, READ));
}
