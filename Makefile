NAME = _printf

SOURSES = _printf.c _puts.c _strchr.c _strlen.c my_main.c \

OBJECTS = $(SOURSES:%.c=%.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

all: $(NAME)

$(NAME):$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: all
	./$(NAME)