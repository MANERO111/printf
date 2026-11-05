/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertToHex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakioud <aakioud@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:19:11 by aakioud           #+#    #+#             */
/*   Updated: 2026/11/03 14:05:32 by aakioud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhex(char *str, int i, size_t *len)
{
	while (i > 0)
	{
		if (ft_putchar(str[--i], len) == -1)
			return (-1);
	}
	return (0);
}

int	ft_converttohex(unsigned int number, int up, size_t *len)
{
	char	str[32];
	char	*base16;
	int		i;

	i = 0;
	if (up)
		base16 = "0123456789ABCDEF";
	else
		base16 = "0123456789abcdef";
	if (number == 0)
	{
		if (ft_putchar('0', len) == -1)
			return (-1);
		return (0);
	}
	while (number > 0)
	{
		str[i++] = base16[number % 16];
		number /= 16;
	}
	return (printhex(str, i, len));
}
