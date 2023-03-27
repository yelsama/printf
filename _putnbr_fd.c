#include "main.h"

/**
 *  _putnbr_fd - count number of digints wihin number
 * @n: number to write
 * @fd: file descriptor
 * Return: number of printed
 */
int	_putnbr_fd(int n, int fd)
{
	char	c;
	int		p;

	p = 0;
	if (n == -2147483648)
		p = write(fd, "-2147483648", 11);
	else if (n == 0)
		p = write(fd, "0", 1);
	else if (n < 0)
	{
		p = write(fd, "-", 1);
		p += _putnbr_fd(-n, fd);
	}
	else if (n < 10)
	{
		c = n + '0';
		p = write(fd, &c, 1);
	}
	else
	{
		p += _putnbr_fd(n / 10, fd);
		p += _putnbr_fd(n % 10, fd);
	}
	return (p);
}
