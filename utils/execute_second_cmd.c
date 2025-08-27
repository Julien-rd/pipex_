/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_second_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:42 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 15:38:35 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_second_cmd(t_proc *proc, char **envp)
{
	char	*path;

	if (close(proc->pipe_fd[1]) < 0)
		exit_process(errno, "close failed", proc);
	if (dup2(proc->pipe_fd[0], STDIN_FILENO) < 0)
		exit_process(errno, "dup failed", proc);
	if (dup2(proc->io_fd[1], STDOUT_FILENO) < 0)
		exit_process(errno, "dup failed", proc);
	if (close(proc->pipe_fd[0]) < 0)
		exit_process(errno, "close failed", proc);
	if (close(proc->io_fd[0]) < 0)
		exit_process(errno, "close failed", proc);
	if (close(proc->io_fd[1]) < 0)
		exit_process(errno, "close failed", proc);
	path = find_path(proc->argvec2[0], envp, proc);
	if (!path)
		exit_process(errno, NULL, proc);
	execve(path, proc->argvec2, envp);
	free(path);
	exit_process(errno, "execve failed", proc);
}
