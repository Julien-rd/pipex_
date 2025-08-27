/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit_codes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:33:57 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 12:34:41 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exit_message(int exit_code, char *cmd)
{
	if (exit_code == 127)
		ft_printf("command not found: %s\n", cmd);
	else if (exit_code == 126)
		ft_printf("access denied");
	else if (exit_code > 0)
		ft_printf("failed");
}

void	ft_check_exit_codes(int status_1, int status_2, t_proc *proc)
{
	int	exit_code;

	exit_code = 0;
	if (WIFEXITED(status_1))
	{
		if(proc->child_proc1 != -1 && proc->argvec1[0])
			ft_exit_message(WEXITSTATUS(status_1), proc->argvec1[0]);
	}
	if (WIFEXITED(status_2))
	{
		exit_code = WEXITSTATUS(status_2);
		if(proc->child_proc2 != -1 && proc->argvec2[0])
			ft_exit_message(exit_code, proc->argvec2[0]);
	}
	ft_cleanup(proc);
	exit(exit_code);
}
