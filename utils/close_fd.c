/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:15:02 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 15:38:46 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_proc *proc)
{
	if (proc->pipe_fd[0] != -1)
	{
		close(proc->pipe_fd[0]);
		proc->pipe_fd[0] = -1;
	}
	if (proc->pipe_fd[1] != -1)
	{
		close(proc->pipe_fd[1]);
		proc->pipe_fd[1] = -1;
	}
	if (proc->io_fd[0] != -1)
	{
		close(proc->io_fd[0]);
		proc->io_fd[0] = -1;
	}
	if (proc->io_fd[1] != -1)
	{
		close(proc->io_fd[1]);
		proc->io_fd[1] = -1;
	}
}
