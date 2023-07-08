#include "ft_printf.h"

static int	ptrlen(unsigned int ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static void	ft_ptrput(unsigned int ptr, char *hex)
{
	if (ptr < 16)
	{
		ft_putchar(hex[ptr % 16]);
	}
	else
	{
		ft_ptrput(ptr / 16, hex);
		ft_putchar(hex[ptr % 16]);
	}
}

int	ft_putptr(unsigned int ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_ptrput(ptr, "0123456789abcdef");
		len += ptrlen(ptr);
	}
	return (len);
}