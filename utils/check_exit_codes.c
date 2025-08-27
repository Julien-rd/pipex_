/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_codes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:33:57 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 15:29:58 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_message(int exit_code, char *cmd, int spec, t_proc *proc)
{
	if (exit_code == 127)
		printf("command not found: %s\n", cmd);
	else if (exit_code == 126)
		printf("access denied");
	else if (exit_code > 0)
		printf("failed");
	if (spec == 1)
	{
		if (proc)
			cleanup(proc);
		if (exit_code == 0)
			return ;
		exit(exit_code);
	}
}

void	check_exit_codes(t_proc *proc)
{
	int	exit_code;
	int	status_1;
	int	status_2;

	status_1 = 0;
	status_2 = 0;
	exit_code = 0;
	if (proc->child_proc1 != -1)
		if (waitpid(proc->child_proc1, &status_1, 0) < 0)
			exit_process(errno, "waitpid failed", proc);
	if (proc->child_proc2 != -1)
		if (waitpid(proc->child_proc2, &status_2, 0) < 0)
			exit_process(errno, "waitpid failed", proc);
	if (WIFEXITED(status_1))
	{
		if (proc->child_proc1 != -1 && proc->argvec1[0])
			exit_message(WEXITSTATUS(status_1), proc->argvec1[0], 0, proc);
	}
	if (WIFEXITED(status_2))
	{
		exit_code = WEXITSTATUS(status_2);
		if (proc->child_proc2 != -1 && proc->argvec2[0])
			exit_message(WEXITSTATUS(status_2), proc->argvec2[0], 1, proc);
	}
}
