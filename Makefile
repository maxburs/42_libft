NAME = libft.a

OBJ = ft_memset.o\
	ft_bzero.o\
	ft_memcpy.o\
	ft_memmove.o\
	ft_memchr.o\
	ft_strlen.o\
	ft_strnew.o

CFLAGS = -Wall -Wextra -Werror -I .

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

ft_memset.o: ft_memset.c
ft_bzero.o: ft_bzero.c
ft_memcpy.o: ft_memcpy.c
ft_memmove.o: ft_memmove.c
ft_memchr.o: ft_memchr.c
ft_strlen.o: ft_strlen.c

ft_strnew.o: ft_strnew.c

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
