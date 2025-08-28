/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:49 by jromann           #+#    #+#             */
/*   Updated: 2025/08/28 13:26:05 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_failed(char *argv, t_proc *proc, int spec)
{
	perror(argv);
	proc->io_fd[spec] = open("/dev/null", O_RDONLY);
	if (proc->io_fd[spec] == -1)
		exit_process(errno, "cannot open /dev/null", proc);
}

void	initialize_values(t_proc *proc, char **argv)
{
	proc->argvec1 = NULL;
	proc->argvec2 = NULL;
	proc->child_proc1 = -1;
	proc->child_proc2 = -1;
	if (pipe(proc->pipe_fd) == -1)
		exit_process(errno, "pipe failed", proc);
	proc->io_fd[0] = open(argv[1], O_RDONLY);
	if (proc->io_fd[1] == -1)
	{
		ft_printf("pipex: permission denied: %s\n", argv[4]);
		exit_process(1, NULL, proc);
	}
	proc->io_fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (proc->io_fd[1] == -1)
		open_failed(argv[4], proc, 1);
	proc->argvec1 = split(argv[2], ' ');
	if (proc->argvec1 == NULL)
		exit_process(errno, NULL, proc);
	proc->argvec2 = split(argv[3], ' ');
	if (proc->argvec2 == NULL)
		exit_process(errno, NULL, proc);
}
