#include "main.h"

void	rules(void)
{
	putStr(cyan);
	putStr("You must find the hidden word. Good luck ! \n");
	putStr(reset);
}

int		calculgameover(int length)
{
	int gameover;
	gameover = 2 * length;
	return (gameover);
}

void	game(char *word, char *hidden, t_counter *counter)
{
	char letter;
	int gameover;
	gameover = calculgameover(counter->length - 1);
	int remind;
	remind = gameover;

	while (counter->length > 1 && gameover != 0)
	{
		putStr(pink);
		putStr(hidden);
		putStr("\n");
		putStr(reset);
		putStr(cyan);
		putStr("Any idea ? \n");
		putStr(reset);
		putStr(purple);
		scanf(" %c", &letter);
		putStr(reset);

		while (word[counter->count] != '\0')
		{
			if (word[counter->count] == letter)
			{
				counter->length--;
				hidden[counter->count] = word[counter->count];
				word[counter->count] = '-';
			}
			else
			{
			}
			counter->count++;
		}
		counter->count = 0;
		gameover--;
		if ((gameover == (remind / 2) && counter->length != 1) || (gameover == (remind / 4) && counter->length != 1))
		{
			putStr(pink);
			putStr("You only have ");
			putNbr(gameover);
			putStr(" chance left.\n");
			putStr(reset);
		}
		while ((getchar()) != '\n')
			;
	}
	counter->count = 0;
}

void	end(char *hidden, char *word, t_counter *counter)
{
	counter->count = 1;
	counter->length = strLength(word);
	int win;
	win = 0;
	while (word[counter->count] != '\0')
	{
		if (word[counter->count] == '-')
		{
			win++;
		}
		counter->count++;
	}
	if (win == counter->length - 1)
	{
		putStr(pink);
		counter->nbWin = counter->nbWin + 1;
		putStr("Good game ! You win !");
		putStr(reset);
	}
	else
	{
		putStr(pink);
		putStr("Game over.");
		putStr(reset);
	}
	counter->count = 0;
	putStr(cyan);
	putStr("\nThe word was : ");
	while (word[counter->count] != '\0')
	{
		if (word[counter->count] == '-')
		{
			putChar(hidden[counter->count]);
		}
		else
		{
			putChar(word[counter->count]);
		}
		counter->count++;
	}
	counter->count = 0;
	putStr("\n");
	putStr(reset);
}
