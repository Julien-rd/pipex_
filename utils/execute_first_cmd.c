/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_first_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:39 by jromann           #+#    #+#             */
/*   Updated: 2025/08/28 13:20:54 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_cmd(t_proc *proc, char **envp)
{
	char	*path;

	if (close(proc->pipe_fd[0]) < 0)
		exit_process(errno, "close failed", proc);
	if (dup2(proc->io_fd[0], STDIN_FILENO) < 0)
		exit_process(errno, "dup failed", proc);
	if (dup2(proc->pipe_fd[1], STDOUT_FILENO) < 0)
		exit_process(errno, "dup failed", proc);
	if (close(proc->pipe_fd[1]) < 0)
		exit_process(errno, "close failed", proc);
	if (close(proc->io_fd[0]) < 0)
		exit_process(errno, "close failed", proc);
	if (close(proc->io_fd[1]) < 0)
		exit_process(errno, "close failed", proc);
	analyse_input(proc->argvec1[0], proc, envp);
	path = find_path(proc->argvec1[0], envp, proc);
	if (!path)
		exit_process(errno, NULL, proc);
	execve(path, proc->argvec1, envp);
	free(path);
	exit_process(errno, "execve failed", proc);
}
