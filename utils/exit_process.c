/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:00:48 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 15:38:51 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_process(int exit_code, char *error_msg, t_proc *proc)
{
	errno = exit_code;
	if (error_msg != NULL)
		perror(error_msg);
	if (proc)
		cleanup(proc);
	exit(exit_code);
}
