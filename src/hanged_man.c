#include "main.h"

void	hangedMan(int argc, char **argv)
{
	t_counter counter;
	counter.count = 0;
	counter.nbRetry = 0;
	counter.countArgv = 1;
	counter.countChar = 0;
	counter.nbWin = 0;
	t_words words;
	int error;
	error = 0;
	int retry;
	retry = 1;
	if (argc == 1)
	{
		putStr(pink);
		putStr("No words, error.\n");
		putStr(reset);
		error = 1;
	}
	if (error == 0)
	{
		words.listWord = NULL;
		words.listWord = copyListWord(words.listWord, argv, argc);
		words.pseudo = NULL;
		words.pseudo = pseudo(words.pseudo);
		while (retry == 1)
		{
			// words.word = NULL;
			words.word = dictionary(words.word, words.listWord, argc - 1, &counter);
			counter.length = strLength(words.word);
			char hidden[counter.length + 1];
			hiddenWord(words.word, hidden, &counter);
			rules();
			game(words.word, hidden, &counter);
			end(hidden, words.word, &counter);
			free(words.word);
			retry = retryHanged(&counter.nbRetry);
		}
		stats(words.listWord, counter.nbRetry, words.pseudo, argc, counter.nbWin);
		free(words.pseudo);
		freeTabStr(words.listWord, argc);
	}
}

int		retryHanged(int *nbRetry)
{
	int error;
	error = 0;
	*nbRetry = *nbRetry + 1;
	char letter;
	while (error == 0)
	{
		putStr(cyan);
		putStr("Wanna play again?");
		putStr("\n");
		putStr("Tape Y for yes and N for no : ");
		putStr(reset);
		putStr(pink);
		putStr("[Y/N]");
		putStr("\n");
		putStr(reset);
		putStr(purple);
		scanf(" %c", &letter);
		putStr(reset);
		if (letter == 'Y' || letter == 'y')
		{
			return (1);
		}
		if (letter == 'N' || letter == 'n')
		{
			putStr(cyan);
			putStr("Goodbye !");
			putStr("\n");
			putStr(reset);
			return (0);
		}
		putStr(pink);
		putStr("Error : ");
		putStr(&letter);
		putStr(" is not [Y/N] please retape one");
		putStr("\n");
		putStr(reset);
		error = 0;
		while ((getchar()) != '\n')
			;
	}
	return (0);
}
