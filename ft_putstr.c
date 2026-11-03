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

void	ft_putstr(char *str, size_t *len)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", len);
	while (str && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		*len += 1;
	}
}
