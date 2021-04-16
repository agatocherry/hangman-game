#include "main.h"

char	*pseudo(char *pseudo)
{
	int		i;
	int		length;
	char	buffer[100] = "";

	i = 0;
	putStr(cyan);
	putStr("Welcome at the hanged man game !\n");
	putStr("Please, tape a pseudo : ");
	putStr(reset);
	putStr(purple);
	read(0, buffer, 100);
	length = strLength(buffer);
	pseudo = (char *)malloc((sizeof(char) * length) + 1);
	while (buffer[i] != '\0')
	{
		pseudo[i] = buffer[i];
		i++;
	}
	pseudo[i] = '\0';
	putStr(reset);
	return (pseudo);
}

void	put_pseudo(int fd, char *pseudo)
{
	int		i;

	i = 0;
	putFdStr("\n\n\n  ", fd);
	while (i < strLength(pseudo) - 1)
	{
		putFdStr("=", fd);
		i++;
	}
	putFdStr("  \n• ", fd);
	i = 0;
	while (pseudo[i])
	{
		if (pseudo[i] != '\n')
			putFd(pseudo[i], fd);
		i++;
	}
	putFdStr(" •\n  ", fd);
	i = 0;
	while (i < strLength(pseudo) - 1)
	{
		putFdStr("=", fd);
		i++;
	}
	putFdStr("  \n\n", fd);
}

void	stats(char **listWord, int retry, char *pseudo, int argc, int nbWin)
{
	int		fd;
	
	fd = open("stat.txt", O_APPEND | O_WRONLY);
	put_pseudo(fd, pseudo);
	putFdStr("  -----  \n| Words |\n  -----  \n\n", fd);
	putFdStr("Number : ", fd);
	putFdNbr((argc - 1), fd);
	putFdStr("\n", fd);
	putFdStr("List : ", fd);
	int nbStr;
	nbStr = 0;
	while (nbStr < argc - 1)
	{
		putFdStr(listWord[nbStr], fd);
		putFdStr(" ", fd);
		nbStr++;
	}
	putFdStr("\n", fd);
	putFdStr("\n", fd);
	putFdStr("  -----  \n| Score |\n  -----  ", fd);
	putFdStr("\n\nWin : ", fd);
	putFdNbr(nbWin, fd);
	putFdStr("\n", fd);
	putFdStr("Lose : ", fd);
	putFdNbr((retry - nbWin), fd);
	putFdStr("\n", fd);
	putFdStr("Try : ", fd);
	putFdNbr(retry, fd);
	putFdStr("\n", fd);
	putFdStr("\n", fd);
	putFdStr("\n----", fd);
}
