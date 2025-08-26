/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:36:37 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 12:12:45 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_message(int spec)
{
	if (spec == 0)
		perror("program needs exactly four arguments");
	if (spec == 1)
		perror("memory allocation failed");
	if (spec == 2)
		perror("pipe function call failed");
	if (spec == 3)
		perror("open function call failed");
	if (spec == 4)
		perror("fork function call failed");
	if (spec == 5)
		exit(127);
	if (spec == 6)
		exit(127);
	if (spec == 7)
		perror("file not found");
	if (spec == 8)
		perror("waitpid function call failed");
	exit(1);
}
