/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakioud <aakioud@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:19:34 by aakioud           #+#    #+#             */
/*   Updated: 2026/11/03 13:18:28 by aakioud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, size_t *len)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)", len));
	while (str && str[i] != '\0')
	{
		if (ft_putchar(str[i], len) == -1)
			return (-1);
		i++;
	}
	return (0);
}
