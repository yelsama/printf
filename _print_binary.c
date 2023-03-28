#include "main.h"

/**
 * _print_binary - check the code
 * @val: the value to be printed
 * Return: number of digits printed
 */
int	_print_binary(unsigned int val)
{
	int		n;
	char	c;

	n = 0;
	if (val > 1)
		n += _print_binary(val / 2);
	c = (val % 2) + '0';
	n += write(1, &c, 1);
	return (n);
}
