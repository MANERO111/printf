
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <unistd.h>

void ft_putchar(char c , size_t *len) {
    write(1, &c, 1);
	*len += 1;
}

void	ft_putnbr(int n, size_t *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-',len);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putchar(nb % 10 + '0',len);
	}
	else
		ft_putchar(nb + '0',len);
}


void	ft_putstr(char *str ,size_t *len)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		*len += 1;
	}
}

void putadress(void *ptr , size_t *len)
{
	char str[32] ;
	char *base16 ;
	int i = 0;	
	unsigned long address = (unsigned long)ptr;
	base16 = "0123456789abcdef";
	if (!ptr)
	{
		write(1, "0x0", 3);
		*len += 3;
		return;
	}
	while (address > 0)
	{
		str[i] = base16[address % 16];
		address /= 16;
		i++;
	}
	write(1,"0x",2);
	*len += 2;
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
		*len += 1;
	}
}

void ft_converttohex(unsigned int number ,int up , size_t *len)
{
	char str[32] ;
	char *base16 ;
	int i = 0;

	if (up)
		base16 = "0123456789ABCDEF";
	else
		base16 = "0123456789abcdef";

	if (number == 0)
	{
    	ft_putchar('0', len);
    	return;
	}
	while (number > 0)
	{
		str[i++] = base16[number % 16];
		number /= 16;
	}
	while (i > 0)
		ft_putchar(str[--i],len);

}

void ft_put_unsigned(unsigned int n, size_t *len)
{
	if(n > 9)
		ft_put_unsigned(n / 10, len);
	ft_putchar(n % 10 + '0',len);
}

int ft_printf(const char *s ,...)
{
	va_list args;
	int i= 0;

	void *ptr;
	size_t len = 0;
	va_start(args,s);
	while(s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (s[i + 1] == 'c')
				ft_putchar(va_arg(args, int),&len);
			else if (s[i + 1] == 'd' || s[i + 1] == 'i')
				ft_putnbr(va_arg(args, int),&len);	
			else if (s[i + 1] == 's')
				ft_putstr(va_arg(args, char *),&len);
			else if (s[i + 1] == 'p')
				putadress(va_arg(args, void *),&len);
			else if(s[i + 1] == 'X')
				ft_converttohex(va_arg(args, int), 1, &len);
			else if (s[i + 1] == 'x')
				ft_converttohex(va_arg(args, int), 0, &len);
			else if (s[i + 1] == 'u')
				ft_put_unsigned(va_arg(args, unsigned int), &len);
			else if (s[i + 1] == '%')
				ft_putchar('%',&len);
			else 
				ft_putchar('%',&len);
			i++;
		}
		else
			ft_putchar(s[i],&len);
		i++;
	}
	va_end(args);
	return ((int)len) ;
}






