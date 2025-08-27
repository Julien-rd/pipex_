/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:52 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 12:32:21 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_proc	*proc;
	int		status_1;
	int		status_2;

	if (argc != 5)
		return (1);
	status_1 = 0;
	status_2 = 0;
	proc = malloc(sizeof(t_proc));
	if (!proc)
		return (1);
	ft_initialize_values(proc, argv);
	proc->child_proc1 = fork();
	if (proc->child_proc1 == -1)
	{
		perror("fork");
		ft_cleanup(proc);
	}
	if (proc->child_proc1 == 0)
		ft_execute_first_cmd(proc, envp);
	proc->child_proc2 = fork();
	if (proc->child_proc2 == -1)
	{
		perror("fork");
		ft_cleanup(proc);
	}
	if (proc->child_proc2 == 0)
		ft_execute_second_cmd(proc, envp);
	ft_close_fd(proc);
	if (proc->child_proc1 != -1)
		waitpid(proc->child_proc1, &status_1, 0);
	if (proc->child_proc2 != -1)
		waitpid(proc->child_proc2, &status_2, 0);
	ft_check_exit_codes(status_1, status_2, proc);
	return (0);
}
