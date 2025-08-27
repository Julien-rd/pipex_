/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:49 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 14:42:08 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_values(t_proc *proc, char **argv)
{
	proc->argvec1 = NULL;
	proc->argvec2 = NULL;
	if (pipe(proc->pipe_fd) == -1)
		exit_process(errno, "pipe failed", proc);
	proc->io_fd[0] = open(argv[1], O_RDONLY);
	proc->io_fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (proc->io_fd[0] == -1 || proc->io_fd[1] == -1)
		exit_process(errno, "open failed", proc);
	proc->argvec1 = split(argv[2], ' ');
	if (proc->argvec1 == NULL)
		exit_process(errno, NULL, proc);
	proc->argvec2 = split(argv[3], ' ');
	if (proc->argvec2 == NULL)
		exit_process(errno, NULL, proc);
}
