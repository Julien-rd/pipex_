/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:52 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 12:15:18 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char *argv[], char **envp)
{
	t_proc	*proc;

	if (argc != 5)
		ft_error_message(0);
	proc = malloc(sizeof(t_proc));
	if (!proc)
		ft_close_fd_free_mem(NULL, 1);
	ft_initialize_values(proc, argv);
	proc->child_proc1 = fork();
	if (proc->child_proc1 == -1)
		ft_close_fd_free_mem(proc, 4);
	if (proc->child_proc1 == 0)
		ft_execute_first_cmd(proc, envp, argv);
	ft_check_for_error(proc->child_proc1, proc);
	proc->child_proc2 = fork();
	if (proc->child_proc2 == -1)
		ft_close_fd_free_mem(proc, 4);
	if (proc->child_proc2 == 0)
		ft_execute_second_cmd(proc, envp, argv);
	ft_check_for_error(proc->child_proc2, proc);
	ft_close_fd_free_mem(proc, 0);
	wait(NULL);
	wait(NULL);
	return (0);
}
