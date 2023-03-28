#ifndef	MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdarg.h>
int		_printf(const char *format, ...);
char	*_strchr(char *s, char c);
int		_strlen(char *s);
int		_puts(char *str);
int		_putnbr_fd(int n, int fd);
int		_print_binary(unsigned int val);
int		_print_octal(unsigned int val);
int		_printhex(unsigned int val, char *base);
int		_putunsinint_fd(unsigned int u, int fd);
int		_print_pointer(unsigned long val, char *base);
int		print_rot13string(char *str);       
#endif
