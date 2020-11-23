.SUFFIXES : .c .o

NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -f

AR = ar

ARFLAGS = -crs

MAIN_FILES = ft_printf controller

CONVERSION_FILES = handle_char \
				handle_decimal \
				handle_hexdecimal \
				handle_percent \
				handle_pointer \
				handle_str \
				handle_udecimal

FORMAT_FILES = handle_flags \
				handle_precision \
				handle_width

UTIL_FILES = extra_utils \
			ft_itoa_base \
			ft_putnbr_base \
			put_utils \
			str_utils

FILES = $(MAIN_FILES) \
		$(addprefix conversion/, $(CONVERSION_FILES)) \
		$(addprefix format/, $(FORMAT_FILES)) \
		$(addprefix utils/, $(UTIL_FILES))

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

LIBFT = ./libft/libft.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	$(AR) -q $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)

# works same internally, but specifying is better.
.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft all

re: fclean all

clean:
		$(MAKE) -C ./libft clean
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) -C ./libft fclean
		$(RM) $(NAME)

.PHONY: all re clean fclean

