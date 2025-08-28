/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:33:57 by jromann           #+#    #+#             */
/*   Updated: 2025/08/28 12:57:52 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_message(int exit_code, char *cmd)
{
	if (exit_code == 127)
		ft_printf("command not found: %s\n", cmd);
	else if (exit_code == 126)
		ft_printf("access denied");
}

void	check_exit_code(t_proc *proc, int child_proc, char **argvec)
{
	int	exit_code;
	int	status;

	status = 0;
	exit_code = 0;
	if (child_proc != -1)
		if (waitpid(child_proc, &status, 0) < 0)
			exit_process(errno, "waitpid failed", proc);
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		if (child_proc != -1 && argvec[0])
			exit_message(WEXITSTATUS(status), argvec[0]);
	}
}
