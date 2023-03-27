# include "main.h"

/**
 * _printhex - check the code
 * @val: the value to be printed
 * @base: the string of 16 digits elemnts
 * @n: number of digits printed
 */
void	_printhex(unsigned int val, char *base, int *n)
{
	if (val > 15)
	{
		*n = *n + 1;
		_printhex(val / 16, base, n);
	}
	write(1, &base[val % 16], 1);
}
