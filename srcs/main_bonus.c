/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:35:36 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/09 20:45:26 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_number_of_argment(int argc)
{
	if (argc < 5)
	{
		ft_putendl_fd("At least four arguments must be specified.", 2);
		return (ERROR);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	t_status	*status;

	if (check_number_of_argment(argc))
		return (ERROR);
	if (status_init(argc, argv, &env, &status))
		return (ERROR);
	process_pipe(status);
	status_free(status);
}