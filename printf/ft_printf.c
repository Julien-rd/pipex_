/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:51:32 by jromann           #+#    #+#             */
/*   Updated: 2025/05/13 18:36:08 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fm, ...)
{
	va_list	args;
	int		total_char;

	if (fm == NULL)
		return (-1);
	va_start(args, fm);
	total_char = 0;
	while (*fm && total_char >= 0)
	{
		if (*fm != '%' || (*fm == '%' && *(++fm) == '%'))
			total_char += write(1, &*fm, 1);
		else if ((*fm == 'c' || *fm == 'd' || *fm == 'i' || *fm == 'x'
				|| *fm == 'X' || *fm == 'u'))
			total_char += ft_printf_arg_int(va_arg(args, int), *fm);
		else if (*fm == 's')
			total_char += ft_putstr(va_arg(args, char *));
		else if (*fm == 'p')
			total_char += ft_hexa((unsigned long)va_arg(args, void *), 2);
		else
			total_char = -1;
		fm++;
	}
	va_end(args);
	return (total_char);
}
