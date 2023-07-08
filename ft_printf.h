#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putptr(unsigned int ptr);
int	ft_putnbr(int nb);
int	ft_printuint(unsigned int u);
int	ft_puthex(unsigned int u, char *hex);

#endif