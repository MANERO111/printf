/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakioud <aakioud@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:19:19 by aakioud           #+#    #+#             */
/*   Updated: 2026/11/03 13:19:35 by aakioud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putadress(void *ptr, size_t *len);
int	ft_converttohex(unsigned int number, int up, size_t *len);
int	ft_putchar(char c, size_t *len);
int	ft_putnbr(int n, size_t *len);
int	ft_putstr(char *str, size_t *len);
int	ft_put_unsigned(unsigned int n, size_t *len);

#endif