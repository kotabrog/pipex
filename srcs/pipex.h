/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:40:26 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/08 18:38:11 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR -1
# define READ 0
# define WRITE 1

typedef struct s_cmd {
	char	*cmd;
	int		pipefd[2];
	int		pid;
}			t_cmd;

typedef struct s_status {
	char	*file1;
	char	*file2;
	int		heredoc_flag;
	t_cmd	**cmd;
	char	**env;
}			t_status;

int		process_pipe(t_status *status);
int		process_command(t_status *status, t_cmd *cmd, t_cmd *next_cmd);

int		status_init(int argc, char **argv, char ***env, t_status **status);
int		status_free(t_status *status);

int		cmd_init(char **argv, t_cmd **cmd);
int		cmd_free(t_cmd ***cmd);

int		ft_close(int *fd);
int		multi_close(int *fd1, int *fd2, int *fd3, int *fd4);

int		ft_malloc(void *pointer, size_t type_size, size_t n);
int		ft_free(void *pointer);

int		ft_strcmp(const char *s1, const char *s2);
void	ft_strcpy(char *p, const char *s, size_t n);
char	*ft_strndup(const char *s, ssize_t n);

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strdup(const char *s);
char	**ft_split(const char *s, char c);

void	debug_status(t_status *status);

#endif
