#include "main.h"


/**
 * non_print - print a string.
 * @s: a pointer.
 * Return: the length of the string.
 */

int non_print(char *s)
{

	int i, l = 0;
	int c;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			write(1, "\\", 1);
			write(1, "x", 1);
			l = l + 2;
			c = s[i];
			if (c < 16)
			{
				write(1, "0", 1);
				l++;
			}
			l = l + _printhex(c, "0123456789ABCDEF");
		}
		else
		{
			write(1, &s[i], 1);
			l++;
		}
	}
	return (l);
}
