/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:47 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 14:22:10 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp, t_proc *proc)
{
	int		i;
	int		z;
	char	**paths;
	char	*c;

	c = "PATH=";
	z = -1;
	paths = NULL;
	while (envp[++z])
	{
		i = -1;
		while (++i < 5)
			if (envp[z][i] != c[i])
				break ;
		if (i == 5)
			break ;
	}
	if (envp && envp[z])
	{
		paths = split(&envp[z][i], ':');
		if (!paths)
			exit_process(errno, NULL, proc);
	}
	return (find_cmd(cmd, paths, proc));
}
