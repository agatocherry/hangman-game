#include "main.h"

char	**copyListWord(char **listWord, char **argv, int argc)
{
	int countArgv;
	countArgv = 1;
	int count;
	count = 0;
	int length;
	length = 0;
	int countChar;
	countChar = 0;
	listWord = (char **)malloc((sizeof(char *) * argc) + 1);
	if (listWord == NULL)
	{
		return NULL;
	}
	while (count < argc - 1)
	{
		length = strLength(argv[countArgv]);
		listWord[count] = mallocStr(listWord[count], length);
		if (listWord[count] == NULL)
		{
			return NULL;
		}
		listWord[count][length] = '\0';
		countChar = 0;
		count++;
		countArgv++;
	}
	listWord[count] = NULL;
	countArgv = 1;
	count = 0;
	countChar = 0;
	while (countArgv < argc)
	{
		while (argv[countArgv][countChar] != '\0')
		{
			listWord[count][countChar] = argv[countArgv][countChar];
			countChar++;
		}
		listWord[count][countChar] = '\0';
		countChar = 0;
		countArgv++;
		count++;
	}
	return (listWord);
}

char	*dictionary(char *word, char **listWord, int argc, t_counter *counter)
{
	int length;
	int aleatory;
	aleatory = rand() % (argc - 1);
	length = strLength(listWord[aleatory]);
	word = mallocStr(word, length);
	if (word == NULL)
	{
		return NULL;
	}
	while (listWord[aleatory][counter->count] != '\0')
	{
		word[counter->count] = listWord[aleatory][counter->count];
		counter->count++;
	}
	word[counter->count] = '\0';
	counter->count = 0;
	return (word);
}

void	hiddenWord(char *word, char *hidden, t_counter *counter)
{
	while (word[counter->count] != '\0')
	{
		if (counter->count == 0)
		{
			hidden[counter->count] = word[counter->count];
			word[counter->count] = '-';
		}
		else
		{
			hidden[counter->count] = '-';
		}
		counter->count++;
	}
	hidden[counter->count] = '\0';
	counter->count = 0;
}