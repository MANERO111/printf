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

void	ft_format(char c, va_list args, size_t *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'p')
		ft_putadress(va_arg(args, void *), len);
	else if (c == 'X')
		ft_converttohex(va_arg(args, int), 1, len);
	else if (c == 'x')
		ft_converttohex(va_arg(args, int), 0, len);
	else if (c == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
	else
	{
		ft_putchar('%', len);
		ft_putchar(c, len);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			ft_format(s[i + 1], args, &len);
			i++;
		}
		else
			ft_putchar(s[i], &len);
		i++;
	}
	va_end(args);
	return ((int)len);
}
