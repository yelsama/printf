#include "main.h"


/**
 * print_rev - prints the reversed string.
 * @s: a pointer to string.
 * Return: nothing
 */

int print_rev(char *s)
{
	int count = 0;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}

	for (count--; count >= 0; count--)
		_puts(&s[count]);

	return (count);
}
