/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:56:46 by jromann           #+#    #+#             */
/*   Updated: 2025/08/28 12:57:07 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_proc
{
	int		pipe_fd[2];
	int		io_fd[2];
	char	**argvec1;
	char	**argvec2;
	int		child_proc1;
	int		child_proc2;
}			t_proc;

char		**split(char const *s, char c);
char		*find_cmd(char *cmd, char **paths, t_proc *proc);
char		*find_path(char *cmd, char **envp, t_proc *proc);
char		*strjoin(char const *s1, char const *s2, char c);
void		initialize_values(t_proc *proc, char **argv);
void		exit_process(int errno_new, char *error_msg, t_proc *proc);
void		execute_second_cmd(t_proc *proc, char **envp);
void		execute_first_cmd(t_proc *proc, char **envp);
void		cleanup(t_proc *proc);
void		check_exit_code(t_proc *proc, int child_proc, char **argvec);
void		close_fd(t_proc *proc);
void		free2d(char **str);
void		analyse_input(char *cmd, t_proc *proc, char **envp);

#endif