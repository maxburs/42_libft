NAME = libft.a

OBJ = src/ft_strnew.o

CFLAGS = -Wall -Wextra -Werror -I .

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

src/ft_strnew.o: src/ft_strnew.c

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
