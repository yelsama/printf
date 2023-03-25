#include "main.h"

/**
 * on_action - check the code
 * @i: index of where thie printing is
 * @argdefiner: flag for type to print
 * @argu: argument of va list for the flag
 * Return: number of printed chars
 */
static int	on_action(int *i, char *argdefiner, va_list argu)
{
	void	*p;
	int		n;
	char	c;

	n = 0;
	if (argdefiner[*i] == 's')
	{
		p = (char *)va_arg(argu, int *);
		if (!p)
		{
			_printf("(null)");
			return (5);
		}
		_puts(p);
		n = _strlen(p) - 1;
	}
	else if (argdefiner[*i] == 'c')
	{
		c = va_arg(argu, int);
		write(1, &c, 1);
	}
	else if (argdefiner[*i] == '%')
		write(1, "%", 1);
	return (n);
}

/**
 * _printf - part of printf
 * @format: contets to print
 * Return: number of printed chars
 */
int	_printf(const char *format, ...)
{
	va_list	atached_arg;
	char	*p;
	char	*cases;
	int		i;
	int		n;

	p = (char *)format;
	cases = "cs%";
	i = -1;
	n = 0;
	va_start(atached_arg, format);
	while (p[++i] && ++n)
	{
		if (p[i] == '%' && _strchr(cases, p[i + 1]))
		{
			i++;
			n += on_action(&i, p, atached_arg);
		}
		else
			write(1, &p[i], 1);
	}
	va_end(atached_arg);
	return (n);
}
