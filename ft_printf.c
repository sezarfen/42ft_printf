#include "ft_printf.h"

static int	ft_type(int s, va_list args)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (s == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		len += ft_putptr(va_arg(args, unsigned int));
	else if (s == 'i' || s == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		len += ft_printuint(va_arg(args, unsigned int));
	else if (s == 'x')
		len += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		len += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (s == '%')
	{
		ft_putchar('%');
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_type(format[i + 1], args);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
