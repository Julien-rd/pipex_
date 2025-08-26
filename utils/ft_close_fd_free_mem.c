/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd_free_mem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:34 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 11:12:25 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd_free_mem(t_proc *proc, int spec)
{
	if (spec == 0)
	{
		close(proc->pipe_fd[0]);
		close(proc->pipe_fd[1]);
		close(proc->io_fd[0]);
		close(proc->io_fd[1]);
		free(proc->argvec1);
		free(proc->argvec2);
		free(proc);
		return ;
	}
	if (proc)
	{
		if (proc->pipe_fd[0] != -1)
			close(proc->pipe_fd[0]);
		if (proc->pipe_fd[1] != -1)
			close(proc->pipe_fd[1]);
		if (proc->io_fd[0] != -1)
			close(proc->io_fd[0]);
		if (proc->io_fd[1] != -1)
			close(proc->io_fd[1]);
		if ((proc->argvec1))
			free(proc->argvec1);
		if ((proc->argvec1))
			free(proc->argvec2);
		free(proc);
	}
	ft_error_message(spec);
}
