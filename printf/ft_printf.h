/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:53:54 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 14:31:13 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		num_l(long long int n, int fd);
int		hexa(unsigned long long int n, int specifier);
int		putstr(char *s);
int		printf_arg_int(int i, char index);
int		ft_printf(const char *format, ...);
size_t	strlen(const char *s);
int		toupper(int ch);

#endif
