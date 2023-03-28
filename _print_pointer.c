#include "main.h"

/**
 * _print_pointer - check the code
 * @val: the value to be printed
 * @base: the string of 16 digits elemnts
 * Return: number of digits printed
 */
int	_print_pointer(unsigned long val, char *base)
{
	int	n;

	if (val > 15)
		n += _print_pointer(val / 16, base);
	n += write(1, &base[val % 16], 1);
	return (n);
}
