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

void	ft_putadress(void *ptr, size_t *len)
{
	char			str[32];
	char			*base16;
	int				i;
	unsigned long	address;

	i = 0;
	address = (unsigned long)ptr;
	base16 = "0123456789abcdef";
	if (!ptr)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	while (address > 0)
	{
		str[i] = base16[address % 16];
		address /= 16;
		i++;
	}
	ft_putstr("0x", len);
	while (i > 0)
	{
		write(1, &str[--i], 1);
		*len += 1;
	}
}
