#include "main.h"

/**
 * _flags - turns on flags.
 * @s: character that holds the flag specifier.
 * @f: pointer to the struct flag.
 *
 * Return: 1 if a flag turned on, 0 otherwise
 */

int _flags(char s, flags_f *f)
{
        i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
