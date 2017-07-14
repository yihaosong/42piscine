NAME = ft_display_file
SRC = srcs/
HEADER = includes/
FLAG = -Wall -Wextra -Werror
.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -I $(HEADER) $(FLAG) -c ft_display_file.c $(SRC)*.c
	gcc *.o -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
