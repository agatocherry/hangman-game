#include "main.h"

void	 putChar(char c)
{
	write(1, &c, 1);
}

void	putStr(char *str)
{
	int count;
	count = 0;
	while (str[count] != '\0')
	{
		putChar(str[count]);
		count++;
	}
}

void	putFd(char c, int fd)
{
	write(fd, &c, 1);
}

void	putFdStr(char *str, int fd)
{
	int count;
	count = 0;
	while (str[count] != '\0')
	{
		putFd(str[count], fd);
		count++;
	}
}

void	putFdNbr(int n, int fd)
{
	long nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		putFd('-', fd);
	}
	if (nb > 9)
	{
		putFdNbr((nb / 10), fd);
	}
	putFd(('0' + nb % 10), fd);
}

void	putNbr(int n)
{
	long nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		putChar('-');
	}
	if (nb > 9)
	{
		putNbr(nb / 10);
	}
	putChar('0' + nb % 10);
}