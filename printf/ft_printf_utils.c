/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:53:36 by jromann           #+#    #+#             */
/*   Updated: 2025/05/15 14:25:11 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_l(long long int n, int fd)
{
	char	str[11];
	int		length;

	length = -1;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		fd += 1;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		str[++length] = n % 10 + '0';
		n /= 10;
	}
	str[++length] = 0;
	while (--length >= 0)
		write(1, &str[length], 1);
	length = (int)ft_strlen((const char *)str);
	return (length + (fd - 1));
}

static int	ft_null_check(int specifier)
{
	if (specifier == 2)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0", 1);
	return (1);
}

int	ft_hexa(unsigned long long int n, int specifier)
{
	char	*base;
	char	str[100];
	int		length;

	base = "0123456789abcdef";
	length = -1;
	if (!n)
		return (ft_null_check(specifier));
	if (specifier == 2)
		write(1, "0x", 2);
	while (n > 0)
	{
		str[++length] = base[n % 16];
		if (specifier == 1)
			str[length] = ft_toupper(str[length]);
		n /= 16;
	}
	str[++length] = 0;
	while (--length >= 0)
		write(1, &str[length], 1);
	length = (int)ft_strlen(str);
	if (specifier == 2)
		length += 2;
	return (length);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[++i])
		write(1, &s[i], sizeof(char));
	return (i);
}

int	ft_printf_arg_int(int i, char index)
{
	int	total_amount;

	total_amount = 0;
	if (index == 'c')
		total_amount += write(1, &i, 1);
	else if (index == 'd' || index == 'i')
		total_amount += ft_num_l((long long int)i, 1);
	else if (index == 'x')
		total_amount += ft_hexa((unsigned int)i, 0);
	else if (index == 'X')
		total_amount += ft_hexa((unsigned int)i, 1);
	else if (index == 'u')
		total_amount += ft_num_l((unsigned int)i, 1);
	return (total_amount);
}
