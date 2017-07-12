NAME = do-op
SRC = srcs/
HEADER = includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -I $(HEADER) -Wall -Wextra -Werror -c main.c $(SRC)*.c
	gcc -I $(HEADER) -Wall -Wextra -Werror *.o -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
