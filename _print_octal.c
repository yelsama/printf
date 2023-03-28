#include "main.h"

/**
 * _print_octal - check the code
 * @val: the value to be printed
 * Return: number of digits printed
 */
int	_print_octal(unsigned int val)
{
	int		n;
	char	c;

	n = 0;
	if (val > 15)
		n += _print_octal(val / 8);
	c = (val % 8) + '0';
	n += write(1, &c, 1);
	return (n);
}
