/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:44 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 20:04:19 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check_path(char *fullpath, t_proc *proc)
{
	if (access(fullpath, F_OK) != 0)
		return (0);
	if (access(fullpath, X_OK) != 0)
	{
		ft_cleanup(proc);
		exit(126);
	}
	return (1);
}

char	*ft_find_cmd(char *cmd, char **paths, t_proc *proc)
{
	int		i;
	char	*fullpath;

	i = -1;
	while (paths[++i])
	{
		fullpath = ft_strjoin(paths[i], cmd, '/');
		if (!fullpath)
		{
			ft_free2d(paths);
			ft_cleanup(proc);
			exit(1);
		}
		if (ft_check_path(fullpath, proc))
		{
			ft_free2d(paths);
			return (fullpath);
		}
		free(fullpath);
	}
	ft_cleanup(proc);
	ft_free2d(paths);
	exit(127);
	return (NULL);
}
