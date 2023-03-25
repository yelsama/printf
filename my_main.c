#include "main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    int len;
    int len2, n1, n2;
    unsigned int ui;
    void *addr;
    char *s1;

    s1 = NULL;
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    n1 = _printf("%s", s1);
    n2 = printf("%s", s1);
   printf("Cmpare mine: %d    original: %d\n", n1, n2);
    n1 = _printf("%");
    n2 = printf("%");
   printf("Cmpare mine: %d    original: %d\n", n1, n2);
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
   len = _printf("Percent:[%%]\n");
   len2 = printf("Percent:[%%]\n");
   printf("Cmpare mine: %d    original: %d\n", len, len2);
    // _printf("Len:[%d]\n", len);
    // printf("Len:[%d]\n", len2);
   n1 = _printf("Unknown:[%r]\n");
    n2 = printf("Unknown:[%r]\n");
   printf("Cmpare mine: %d    original: %d\n", n1, n2);
    return (0);
}




// #include "main.h"

// /**
//  *  getdigits - count number of digints wihin number
//  * @num: number to count its digits
//  * Return: number of digints in an i
//  */
// int	getdigits(int num)
// {
// 	int	d;

// 	d = 0;
// 	if (num == -2147483648)
// 		return (10);
// 	if (num < 0)
// 	{
// 		num *= -1;
// 		return (getdigits(num) + 1);
// 	}
// 	if (num >= 0 && num < 10)
// 		return (0);
// 	if (num == 10)
// 		return (1);
// 	while (num != 0)
// 	{
// 		num /= 10;
// 		d++;
// 	}
// 	return (d - 1);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	c;

// 	if (n == -2147483648)
// 		write(fd, "-2147483648", 11);
// 	else if (n == 0)
// 		write(fd, "0", 1);
// 	else if (n < 0)
// 	{
// 		write(fd, "-", 1);
// 		ft_putnbr_fd(-n, fd);
// 	}
// 	else if (n < 10)
// 	{
// 		c = n + '0';
// 		write(fd, &c, 1);
// 	}
// 	else
// 	{
// 		ft_putnbr_fd(n / 10, fd);
// 		ft_putnbr_fd(n % 10, fd);
// 	}
// }

// /**
//  * on_action - check the code
//  * @i: index of where thie printing is
//  * @argdefiner: flag for type to print
//  * @argu: argument of va list for the flag
//  * Return: number of printed chars
//  */
// int	on_action(int *i, char *argdefiner, va_list argu)
// {
// 	void	*p;
// 	int		n, m;
// 	char	c;

// 	n = 0;
// 	if (argdefiner[*i] == 's')
// 	{	
// 		p = (char *)va_arg(argu, int *);
// 		if (!p)
// 		{
// 			_printf("(null)");
// 			return (5);
// 		}
// 		_printf(p);
// 		n = _strlen(p) - 1;
// 	}
// 	else if (argdefiner[*i] == 'c')
// 	{
// 		c = va_arg(argu, int);
// 		write(1, &c, 1);
// 	}
// 	else if (argdefiner[*i] == '%')
// 		write(1, "%", 1);
// 	else if (argdefiner[*i] == 'd' || argdefiner[*i] == 'i')
// 	{
// 		m = va_arg(argu, int);
// 		ft_putnbr_fd(m, 1);
// 		n = getdigits(m);
// 	}
// 	return (n);
// }

// /**
//  * _printf - part of printf
//  * @format: contets to print
//  * Return: number of printed chars
//  */
// int	_printf(const char *format, ...)
// {
// 	va_list	atached_arg;
// 	char	*p;
// 	char	*cases;
// 	int		i;
// 	int		n;

// 	p = (char *)format;
// 	cases = "csdi%";
// 	i = -1;
// 	n = 0;
// 	va_start(atached_arg, format);
// 	while (p[++i] && ++n)
// 	{
// 		if (p[i] != '%')
// 			write(1, &p[i], 1);
// 		else if (p[i] == '%' && _strchr(cases, p[i + 1]))
// 		{
// 			i++;
// 			n += on_action(&i, p, atached_arg);
// 		}
// 	}
// 	va_end(atached_arg);
// 	return (n);
// }

