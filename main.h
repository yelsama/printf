#ifndef	MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
int		_printf(const char *format, ...);
char	*_strchr(char *s, char c);
int		_strlen(char *s);
int		_puts(char *str);
int		_putnbr_fd(int n, int fd);
int		_printhex(unsigned int val, char *base);
int		_putunsinint_fd(unsigned int u, int fd);

#endif
