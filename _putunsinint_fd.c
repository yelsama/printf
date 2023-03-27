#include "main.h"


/**
 * _putunsinint_fd - check the code
 * @u: unsigned int
 * @fd: file descriptor to use with write
 * Return: nubmer of printed chars
 */
int	_putunsinint_fd(unsigned int u, int fd)
{
	int	n;

	n = 0;
	if (u > 9)
		n += _putunsinint_fd(u / 10, fd);
	u = (u % 10) + 48;
	n += write(fd, &u, 1);
	return (n);
}
