/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:59:40 by jromann           #+#    #+#             */
/*   Updated: 2025/08/28 13:22:25 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	analyse_input(char *cmd, t_proc *proc, char **envp)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		exit_process(errno, NULL, proc);
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			execve(cmd, proc->argvec1, envp);
			exit_process(errno, cmd, proc);
		}
		i++;
	}
}
