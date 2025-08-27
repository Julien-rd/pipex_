/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:53:54 by jromann           #+#    #+#             */
/*   Updated: 2025/08/26 18:17:28 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_num_l(long long int n, int fd);
int		ft_hexa(unsigned long long int n, int specifier);
int		ft_putstr(char *s);
int		ft_printf_arg_int(int i, char index);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_toupper(int ch);

#endif
