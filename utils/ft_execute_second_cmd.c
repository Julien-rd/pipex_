/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_second_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:42 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 11:38:35 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_execute_second_cmd(t_proc *proc, char **envp, char **argv)
{
	char	*path;

	close(proc->pipe_fd[1]);
	dup2(proc->pipe_fd[0], STDIN_FILENO);
	dup2(proc->io_fd[1], STDOUT_FILENO);
	close(proc->pipe_fd[0]);
	close(proc->io_fd[0]);
	close(proc->io_fd[1]);
	proc->argvec2 = ft_split(argv[3], ' ');
	if (!proc->argvec2)
		ft_close_fd_free_mem(proc, 1);
	path = ft_find_path(proc->argvec2[0], envp, proc);
	if (!path)
		ft_close_fd_free_mem(proc, 1);
	execve(path, proc->argvec2, envp);
	ft_close_fd_free_mem(proc, 5);
}
