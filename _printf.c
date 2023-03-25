#include "main.h"

/**
 *  getdigits - count number of digints wihin number
 * @num: number to count its digits
 * Return: number of digints in an int
 */
int	getdigits(int num)
{
	int	d;

	d = 0;
	if (num == -2147483648)
		return (10);
	if (num < 0)
	{
		num *= -1;
		return (getdigits(num) + 1);
	}
	if (num >= 0 && num < 10)
		return (0);
	if (num == 10)
		return (1);
	while (num != 0)
	{
		num /= 10;
		d++;
	}
	return (d - 1);
}

/**
 *  _putunsinint_fd - check the code
 * @u: unsigned int
 * @fd: file descriptor to write the code
 * @n: traking number of printed chars
 */
static void	_putunsinint_fd(unsigned int u, int fd, int *n)
{
	if (u > 9)
	{
		*n += 1;
		_putunsinint_fd(u / 10, fd, n);
	}
	u = (u % 10) + 48;
	write(fd, &u, 1);
}

/**
 * on_action2 - check the code
 * @i: index of where thie printing is
 * @argdefiner: flag for type to print
 * @argu: argument of va list for the flag
 * Return: number of printed chars
 */
static int	on_action2(int *i, char *argdefiner, va_list argu)
{
	int	n;

	n = 0;
	if (argdefiner[*i] == 'u')
		_putunsinint_fd(va_arg(argu, unsigned int), 1, &n);
	else if (argdefiner[*i] == '%')
		write(1, "%", 1);
	return (n);
}

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

	p = (char *)format;
	cases = "cspu%";
	i = -1;
	n = 0;
	va_start(atached_arg, format);
	while (p[++i] && ++n)
	{
		if (p[i] != '%')
			write(1, &p[i], 1);
		else if (p[i] == '%' && _strchr(cases, p[i + 1]))
		{
			i++;
			n += on_action(&i, p, atached_arg);
		}
	}
	va_end(atached_arg);
	return (n);
}
