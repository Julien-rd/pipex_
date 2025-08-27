/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:44 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 14:21:41 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_path(char *fullpath, char **paths, t_proc *proc)
{
	if (access(fullpath, F_OK) != 0)
	{
		if (errno == EIO)
		{
			free(fullpath);
			free2d(paths);
			exit_process(errno, "access failed", proc);
		}
		return (0);
	}
	if (access(fullpath, X_OK) != 0)
	{
		if (errno == EIO)
		{
			free(fullpath);
			free2d(paths);
			exit_process(errno, "access failed", proc);
		}
		cleanup(proc);
		exit(126);
	}
	return (1);
}

char	*find_cmd(char *cmd, char **paths, t_proc *proc)
{
	int		i;
	char	*fullpath;

	i = -1;
	while (paths[++i])
	{
		fullpath = strjoin(paths[i], cmd, '/');
		if (!fullpath)
		{
			free2d(paths);
			exit_process(errno, NULL, proc);
		}
		if (check_path(fullpath, paths, proc))
		{
			free2d(paths);
			return (fullpath);
		}
		free(fullpath);
	}
	free2d(paths);
	cleanup(proc);
	exit(127);
	return (NULL);
}
