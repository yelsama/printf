#include "main.h"

/**
 * _strchr - check the code
 * @s: string to set
 * @c: character to find in string
 * Return: pointer to the char
 */
char	*_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (0);
}
