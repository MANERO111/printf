/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakioud <aakioud@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:19:16 by aakioud           #+#    #+#             */
/*   Updated: 2026/11/03 14:05:57 by aakioud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_error(int status, va_list args)
{
	if (status == -1)
	{
		va_end(args);
		return (-1);
	}
	return (0);
}

int	ft_format(char c, va_list args, size_t *len)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int), len));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), len));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), len));
	else if (c == 'p')
		return (ft_putadress(va_arg(args, void *), len));
	else if (c == 'X')
		return (ft_converttohex(va_arg(args, unsigned int), 1, len));
	else if (c == 'x')
		return (ft_converttohex(va_arg(args, unsigned int), 0, len));
	else if (c == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int), len));
	else if (c == '%')
		return (ft_putchar('%', len));
	else
	{
		if (ft_putchar('%', len) == -1)
			return (-1);
		return (ft_putchar(c, len));
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (ft_check_error(ft_format(s[i + 1], args, &len), args) == -1)
				return (-1);
			i++;
		}
		else if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		else if (ft_check_error(ft_putchar(s[i], &len), args) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return ((int)len);
}
