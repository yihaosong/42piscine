NAME = eval_expr
HEADER = includes/
SRC = srcs/
FLAG = -Wall -Wextra -Werror
.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -I $(HEADER) $(FLAG) -c main.c $(SRC)*.c
	gcc *.o -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
