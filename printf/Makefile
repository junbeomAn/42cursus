NAME = ft_printf.a

FLAGS = -Werror -Wall -Wextra

MEM_CHECK = -g3 -fsanitize=address

RM = rm -rf

MAIN_FILES = ft_printf controller

FORMAT_STR_FILES = char decimal hexdecimal precent pointer str udecimal \
				   flags precision width

UTIL_FILES = extra_utils ft_itoa_base ft_putnbr_base put_utils str_utils

FILES = $(MAIN_FILES) $(addprefix handle_, $(FORMAT_STR_FILES)) $(UTIL_FILES)

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):

re: fclean all

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
.PHONY: all re clean fclean
