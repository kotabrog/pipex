/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:45:51 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/08 19:19:00 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	n;

	n = ft_strlen(s);
	write(fd, s, n);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	dst = malloc(ft_strlen(s) + 1);
	if (!dst)
		return (0);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	p = malloc(sizeof(char) * (n1 + n2 + 1));
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, s1, n1);
	ft_strcpy(p + n1, s2, n2);
	p[n1 + n2] = '\0';
	return (p);
}
