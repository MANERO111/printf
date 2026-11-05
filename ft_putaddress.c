/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakioud <aakioud@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:19:22 by aakioud           #+#    #+#             */
/*   Updated: 2026/11/03 13:16:17 by aakioud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printaddress(char *str, int i, size_t *len)
{
	if (ft_putstr("0x", len) == -1)
		return (-1);
	while (i > 0)
	{
		if (ft_putchar(str[--i], len) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putadress(void *ptr, size_t *len)
{
	char			str[32];
	char			*base16;
	int				i;
	unsigned long	address;

	i = 0;
	address = (unsigned long)ptr;
	base16 = "0123456789abcdef";
	if (!ptr)
		return (ft_putstr("(nil)", len) == -1);
	while (address > 0)
	{
		str[i] = base16[address % 16];
		address /= 16;
		i++;
	}
	return (printaddress(str, i, len));
}
