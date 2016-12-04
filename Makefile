NAME = libft.a

OBJS = \
	ft_strplace.o\
	ft_numlen.o\
	\
	ft_memset.o\
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
	ft_strrchr.o\
	ft_strstr.o\
	ft_strnstr.o\
	ft_strcmp.o\
	ft_strncmp.o\
	ft_atoi.o\
	ft_isalpha.o\
	ft_isdigit.o\
	ft_isalnum.o\
	ft_isascii.o\
	ft_isprint.o\
	ft_toupper.o\
	ft_tolower.o\
	\
	ft_memalloc.o\
	ft_memdel.o\
	ft_strnew.o\
	ft_strdel.o\
	ft_strclr.o\
	ft_striter.o\
	ft_striteri.o\
	ft_strmap.o\
	ft_strmapi.o\
	ft_strequ.o\
	ft_strnequ.o\
	ft_strsub.o\
	ft_strjoin.o\
	ft_strtrim.o\
	ft_strsplit.o\
	ft_itoa.o\
	ft_putchar.o\
	ft_putstr.o\
	ft_putendl.o\
	ft_putnbr.o\
	ft_putchar_fd.o

NEEDLIB = ft_strdup.o\
	ft_strnew.o\
	ft_strjoin.o\
	ft_strtrim.o\
	ft_strsplit.o\
	ft_itoa.o\
	ft_putstr.o\
	ft_putendl.o

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
