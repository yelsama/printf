#include "main.h"

/**
 * _strlen - fins length of string
 * @s: a pointer to string
 * Return: string length
 */
int	_strlen(char *s)
{
	int	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}
