#include "main.h"

/**
 * get_print_pointer - check the code
 * @p: pointer value
 * Return: number of printed chars
 */
int	get_print_pointer(unsigned long p)
{
	int	n;

	if (p == 0)
		return (_puts("(nil)"));
	n = _puts("0x");
	n += _print_pointer(p, "0123456789abcdef");
	return (n);
}

/**
 * on_action2 - check the code
 * @i: index of where thie printing is
 * @argdefiner: flag for type to print
 * @argu: argument of va list for the flag
 * Return: number of printed chars
 */
int	on_action2(int i, char *argdefiner, va_list argu)
{
	void	*p;
	int		n;

	n = 0;
	if (argdefiner[i] == 'p')
		n = get_print_pointer((unsigned long)va_arg(argu, void *));
	else if (argdefiner[i] == 'R')
	{
		p = (char *)va_arg(argu, int *);
		if (!p)
			n = _puts("(null)");
		else
			n = print_rot13string(p);
	}
	else if (argdefiner[i] == 'r')
	{
		p = (char *)va_arg(argu, int *);
		if (!p)
			n = _puts("(null)");
		else
		{
			rev_string(p);
			n = _puts(p);
		}
	}
	return (n);
}

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
	else if (argdefiner[i] == 'o')
		n = _print_octal(va_arg(argu, int));
	else if (argdefiner[i] == 'b')
		n = _print_binary(va_arg(argu, int));
	else
		n = on_action2(i, argdefiner, argu);
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
	cases = "csdibuoxXpRr%";
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
