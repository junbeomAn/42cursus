
CFLAGS	= -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

CFILES	= ./ft_*.c

OBJS	= $(CFILES:.c=.o)

TARGET	= libft.a

all:		$(TARGET)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(TARGET)

re:			fclean all

${TARGET}:	$(OBJS)
			ar -crs $@ $(OBJS)