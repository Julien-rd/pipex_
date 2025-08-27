/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:49 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 19:28:33 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_initialize_values(t_proc *proc, char **argv)
{
	proc->argvec1 = NULL;
	proc->argvec2 = NULL;
	if (pipe(proc->pipe_fd) == -1)
	{
		perror("pipe");
		ft_cleanup(proc);
		exit(1);
	}
	proc->io_fd[0] = open(argv[1], O_RDONLY);
	proc->io_fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (proc->io_fd[0] == -1 || proc->io_fd[1] == -1)
	{
		perror("open");
		ft_cleanup(proc);
		exit(1);
	}
	proc->argvec1 = ft_split(argv[2], ' ');
	if (!proc->argvec1)
	{
		ft_cleanup(proc);
		exit(1);
	}
	proc->argvec2 = ft_split(argv[3], ' ');
	if (!proc->argvec2)
	{
		ft_cleanup(proc);
		exit(1);
	}
}
