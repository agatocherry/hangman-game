#ifndef __MAIN__H
#define __MAIN__H

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define cyan "\033[0;36m"
#define pink "\033[1;35m"
#define purple "\033[0;34m"
#define reset "\033[0m"

typedef struct	s_counter
{
	int		length;
	int		count;
	int		countArgv;
	int		countChar;
	char	c;
	int		nbRetry;
	int		nbWin;
}				t_counter;

typedef struct	s_words
{
	char	**listWord;
	char	*word;
	char	*pseudo;
}				t_words;

/*
** stat.c
*/

char		*pseudo(char *);
void		stats(char **, int, char *, int, int);

/*
** print.c
*/

void		putChar(char);
void		putStr(char *);
void		putFd(char, int);
void		putFdStr(char *, int fd);
void		putFdNbr(int n, int fd);
void		putNbr(int n);

/*
** malloc.c
*/

char		*mallocStr(char *, int);
char		**mallocTabStr(char **, int, int);
void		freeTabStr(char **, int);

/*
** math.c
*/

int			random_number(int, int);
int			strLength(char *);

/*
** word.c
*/

char		**copyListWord(char **, char **, int);
char		*dictionary(char *, char **, int, t_counter *);
void		hiddenWord(char *, char *, t_counter *);

/*
** game.c
*/

void		rules(void);
int			calculgameover(int);
void		game(char *, char *, t_counter *);
void		end(char *, char *, t_counter *);

/*
** stat.c
*/

void		hangedMan(int, char **);
int			retryHanged(int *);

#endif
