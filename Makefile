CC = gcc
OUTPUT = my_mastermind
CFLAGS += -Wall -Wextra -Werror
SOURCES = my_mastermind.c game_logic.c
HEADERS = my_mastermind.h
OBJECTS = $(SOURCES:.c=.o) $(HEADERS)


$(OUTPUT): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(OUTPUT)

fclean: clean
	rm -f ${OUTPUT}

re: fclean all
