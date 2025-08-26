/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:47 by jromann           #+#    #+#             */
/*   Updated: 2025/08/25 09:00:40 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char *cmd, char **envp, t_proc *proc)
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
		paths = ft_split(&envp[z][i], ':');
		if (!paths)
			ft_close_fd_free_mem(proc, 1);
	}
	return (ft_find_cmd(cmd, paths, proc));
}
