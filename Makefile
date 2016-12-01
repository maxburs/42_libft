NAME = libft.a

OBJS = ft_memset.o\
	ft_bzero.o\
	ft_memcpy.o\
	ft_memmove.o\
	ft_memchr.o\
	ft_strlen.o\
	ft_strdup.o\
	ft_strcpy.o\
	ft_strncpy.o\
	ft_strcat.o\
	ft_strncat.o\
	ft_strlcat.o\
	ft_strchr.o\
	ft_strnew.o

NEEDLIB = ft_strdup.o\
	ft_strnew.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -I . -c -o $@ $<

$(NEEDLIB): libft.h

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
