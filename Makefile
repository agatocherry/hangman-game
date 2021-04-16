CC = gcc
INCLUDEFILES = main.h
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -L $(INCLUDEFILES)
SOURCES = src/main.c src/game.c src/hanged_man.c src/malloc.c src/math.c src/print.c src/stat.c src/word.c
OBJS = ${SOURCES:.c=.o}
NAME = play
PURPLE=$'\x1b[34m
PINK=$'\x1b[35m
END=$'\x1b[0m

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	@echo "${PURPLE}Compiling $(NAME) done${END}"
	@echo "${PINK}Please tape ./play before the list of your words${END}"
	@echo "${PINK}After your party you can see your stat in stat.txt file${END}"

clean: 
	@rm -rf $(OBJS)
	@echo "${PURPLE}! Removed objects files${END}"

fclean: clean
	@rm -rf $(NAME)
	@echo "${PURPLE}! Removed $(NAME)${END}"

re: fclean all

.PHONY: all clean fclean re install