#include "main.h"

/**
 * _printhex - check the code
 * @val: the value to be printed
 * @base: the string of 16 digits elemnts
 * Return: number of digits printed
 */
int	_printhex(unsigned int val, char *base)
{
	int	n;

	n = 0;
	if (val > 15)
		n += _printhex(val / 16, base);
	n += write(1, &base[val % 16], 1);
	return (n);
}
