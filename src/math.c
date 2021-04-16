#include "main.h"

int		random_number(int min_num, int max_num)
{
	int r = rand() % max_num;
	(void)min_num;
	return (r);
}

int		strLength(char *word)
{
	int count;
	count = 0;
	while (word[count] != '\0')
	{
		count++;
	}
	return (count);
}