#include "main.h"

/**
 * on_action - check the code
 * @i: index of where thie printing is
 * @argdefiner: flag for type to print
 * @argu: argument of va list for the flag
 * Return: number of printed chars
 */
int	on_action(int i, char *argdefiner, va_list argu)
{
	void	*p;
	int		n, m;
	char	c;

	n = 0;
	if (!argu)
		return (1);
	if (argdefiner[i] == 's')
	{
		p = (char *)va_arg(argu, int *);
		if (!p)
			n = _puts("(null)");
		else
			n = _puts(p);
	}
	else if (argdefiner[i] == 'c')
	{
		c = va_arg(argu, int);
		n = write(1, &c, 1);
	}
	else if (argdefiner[i] == 'd' || argdefiner[i] == 'i')
	{
		m = va_arg(argu, int);
		n = _putnbr_fd(m, 1);
	}
	else if (argdefiner[i] == '%')
		n = write(1, "%", 1);
	else if (argdefiner[i] == 'x')
		n = _printhex(va_arg(argu, int), "0123456789abcdef");
	else if (argdefiner[i] == 'X')
		n = _printhex(va_arg(argu, int), "0123456789ABCDEF");
	else if (argdefiner[i] == 'u')
		n = _putunsinint_fd(va_arg(argu, unsigned int), 1);
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

	if (!format)
		return (-1);
	p = (char *)format;
	cases = "csdiuxX%";
	i = -1;
	n = 0;
	va_start(atached_arg, format);
	while (p[++i])
	{
		if (p[i] == '%' && _strchr(cases, p[i + 1]))
		{
			i++;
			if (!p[i])
				return (-1);
			n += on_action(i, p, atached_arg);
		}
		else
		{
			write(1, &p[i], 1);
			n++;
		}
	}
	va_end(atached_arg);
	return (n);
}
