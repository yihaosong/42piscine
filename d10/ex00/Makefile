NAME = libft.a
SRC = srcs/
HEADER = includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -I $(HEADER) -Wall -Wextra -Werror -c $(SRC)*.c
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
