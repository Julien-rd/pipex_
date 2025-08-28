/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:52 by jromann           #+#    #+#             */
/*   Updated: 2025/08/28 13:21:39 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_proc	*proc;

	if (argc != 5)
		return (1 + ft_printf("program needs 4 args") * 0);
	proc = malloc(sizeof(t_proc));
	if (!proc)
		exit_process(errno, "malloc failed", proc);
	initialize_values(proc, argv);
	proc->child_proc1 = fork();
	if (proc->child_proc1 == -1)
		exit_process(errno, "fork failed", proc);
	if (proc->child_proc1 == 0)
		execute_first_cmd(proc, envp);
	check_exit_code(proc, proc->child_proc1, proc->argvec1);
	execute_second_cmd(proc, envp);
	return (0);
}
