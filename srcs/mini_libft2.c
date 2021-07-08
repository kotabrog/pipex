/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:04:51 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/08 18:45:44 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	split_one_set(const char *str, char c, \
	size_t *str_count, char **dst)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		++i;
	*str_count += i;
	if (i == 0)
		return (0);
	*dst = ft_strndup(str, i);
	return (*dst == NULL);
}

static int	split_set(const char *str, char c, char **dst)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (split_one_set(str + i, c, &i, &(dst[j])))
		{
			while (j > 0)
				free(dst[--j]);
			return (1);
		}
		++j;
	}
	return (0);
}

static int	split_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	if (*s != c)
		++count;
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			++count;
		++i;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	size_t	count;
	char	**p;

	count = split_count(s, c);
	p = malloc(sizeof(char *) * (count + 1));
	if (p == NULL)
		return (NULL);
	if (count != 0 && split_set(s, c, p))
	{
		free(p);
		return (NULL);
	}
	p[count] = NULL;
	return (p);
}
