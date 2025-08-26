/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_first_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:39 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 12:27:23 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_first_cmd(t_proc *proc, char **envp, char **argv)
{
	char	*path;

	exit(1);
	close(proc->pipe_fd[0]);
	dup2(proc->io_fd[0], STDIN_FILENO);
	dup2(proc->pipe_fd[1], STDOUT_FILENO);
	close(proc->pipe_fd[1]);
	close(proc->io_fd[0]);
	close(proc->io_fd[1]);
	proc->argvec1 = ft_split(argv[2], ' ');
	if (!proc->argvec1)
		ft_close_fd_free_mem(proc, 1);
	path = ft_find_path(proc->argvec1[0], envp, proc);
	if (!path)
		ft_close_fd_free_mem(proc, 1);
	execve(path, proc->argvec1, envp);
	ft_close_fd_free_mem(proc, 5);
}
