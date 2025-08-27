/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:56:46 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 20:03:34 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
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

char		**ft_split(char const *s, char c);
char		*ft_find_cmd(char *cmd, char **paths, t_proc *proc);
char		*ft_find_path(char *cmd, char **envp, t_proc *proc);
char		*ft_strjoin(char const *s1, char const *s2, char c);
void		ft_initialize_values(t_proc *proc, char **argv);
void		ft_execute_second_cmd(t_proc *proc, char **envp);
void		ft_execute_first_cmd(t_proc *proc, char **envp);
void		ft_cleanup(t_proc *proc);
void		ft_check_exit_codes(int status_1, int status_2, t_proc *proc);
void		ft_close_fd(t_proc *proc);
void		ft_free2d(char **str);

#endif