/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:40:26 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/07 00:29:26 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR -1

typedef struct s_cmd {
	char	*cmd;
	int		pipefd[2];
	int		fd;
}			t_cmd;

typedef struct s_status {
	char	*file1;
	char	*file2;
	int		heredoc_flag;
	t_cmd	**cmd;
	char	**env;
}			t_status;

int		status_init(int argc, char **argv, char ***env, t_status **status);
int		status_free(t_status *status);

int		cmd_init(char **argv, t_cmd **cmd);
int		cmd_free(t_cmd ***cmd);

int		ft_malloc(void *pointer, size_t type_size, size_t n);
int		ft_free(void *pointer);

int		ft_strcmp(const char *s1, const char *s2);

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strdup(const char *s);

void	debug_status(t_status *status);

#endif
