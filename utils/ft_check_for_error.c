/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:08:53 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 12:29:03 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_check_for_error(int pid, t_proc *proc)
{
	int status;

	waitpid(pid, &status, WNOHANG);
	if (status == -1)
		ft_close_fd_free_mem(proc, 8);
	if (status == 0)
		return ;
	ft_close_fd_free_mem(proc, 9);
}