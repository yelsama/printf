#include "main.h"

/**
 * _puts - check the code
 * @str: a string to be printed
 */
int	_puts(char *str)
{
	int	n;

	n = 0;
	while (str && *str)
		n += write(1, str++, 1);
	return (n);
}
