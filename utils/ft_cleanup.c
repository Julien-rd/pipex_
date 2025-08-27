/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:34 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 12:32:03 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cleanup(t_proc *proc)
{
	if (proc->pipe_fd[0] != -1)
		close(proc->pipe_fd[0]);
	if (proc->pipe_fd[1] != -1)
		close(proc->pipe_fd[1]);
	if (proc->io_fd[0] != -1)
		close(proc->io_fd[0]);
	if (proc->io_fd[1] != -1)
		close(proc->io_fd[1]);
	if (proc->argvec1)
		ft_free2d(proc->argvec1);
	if (proc->argvec2)
		ft_free2d(proc->argvec2);
	free(proc);
}
