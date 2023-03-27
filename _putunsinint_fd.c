#include "main.h"


/**
 * _putunsinint_fd - check the code
 * @u: unsigned int
 * @fd: file descriptor to use with write
 * @n: number of printed arguments
 */
void	_putunsinint_fd(unsigned int u, int fd, int *n)
{
	if (u > 9)
	{
		*n += 1;
		_putunsinint_fd(u / 10, fd, n);
	}
	u = (u % 10) + 48;
	write(fd, &u, 1);
}
