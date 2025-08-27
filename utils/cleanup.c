/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:34 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 15:05:38 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleanup(t_proc *proc)
{
	free2d(proc->argvec1);
	free2d(proc->argvec2);
	close_fd(proc);
	free(proc);
	proc = NULL;
}
