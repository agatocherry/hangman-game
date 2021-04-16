#include "main.h"

char	*mallocStr(char *str, int length)
{
	str = (char *)malloc((sizeof(char) * length) + 1);
	if (str == NULL)
	{
		return NULL;
	}
	return (str);
}

void	freeTabStr(char **tabStr, int lengthWords)
{
	int count;
	count = 0;
	while (count < lengthWords)
	{
		free(tabStr[count]);
		count++;
	}
	free(tabStr);
}
