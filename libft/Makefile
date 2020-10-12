.SUFFIXES : .c .o

CFLAGS = -Wall -Wextra -Werror

CC = gcc

AR = ar crs

RM = rm -f

NAME = libft.a

FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
		ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strnstr ft_strncmp \
		ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper \
		ft_tolower ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
		ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

FILES_BNS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
	  		ft_lstclear ft_lstiter ft_lstmap

SRCS = $(addsuffix .c, $(FILES))

SRCS_BNS = $(addsuffix .c, $(FILES_BNS))


OBJS = $(addsuffix .o, $(FILES))

OBJS_BNS = $(addsuffix .o, $(FILES_BNS))

all: $(NAME)

.c.o: $(SRCS) $(SRCS_BNS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BNS)

fclean: clean
	$(RM) $(NAME)

re: clean all

bonus: $(OBJS_BNS)
	$(AR) $(NAME) $(OBJS_BNS)

.PHONY: all clean fclean re bonus
