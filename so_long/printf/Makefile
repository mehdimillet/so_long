NAME = libftprintf.a

SOURCES = ft_printf_tools.c ft_printf_tools2.c ft_printf.c

OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs

all: $(NAME)
$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
