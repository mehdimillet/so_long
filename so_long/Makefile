# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memillet <memillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 22:48:21 by memillet          #+#    #+#              #
#    Updated: 2025/11/29 22:18:38 by memillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES =	$(SRC_DIR)/main.c\
			$(SRC_DIR)/parsing/parsing.c\
			$(SRC_DIR)/parsing/parsing2.c\
		  	$(SRC_DIR)/player/player.c\
			$(SRC_DIR)/tools/tools.c\
			$(SRC_DIR)/tools/tools2.c\
			$(SRC_DIR)/tools/tools3.c\
			$(SRC_DIR)/window/initialisation.c\
			$(GNL_DIR)/get_next_line.c\
			$(GNL_DIR)/get_next_line_utils.c

SRC_DIR = src
GNL_DIR = gnl
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
CC = cc
PRINTF = printf/libftprintf.a

# Chemins et flags pour MLX (Linux)
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INCLUDES = -I$(MLX_DIR)
PRINTF_INCLUDES = -Iprintf

INCLUDES = -I$(GNL_DIR) -I$(SRC_DIR) $(MLX_INCLUDES) $(PRINTF_INCLUDES)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(MLX_DIR)
	@make -C printf
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_FLAGS) $(PRINTF) -o $(NAME)

%.o: %.c so_long.h
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean -C $(MLX_DIR)
	@make clean -C printf
	$(RM) $(OBJECTS)

fclean: clean
	@make clean -C $(MLX_DIR)
	@make fclean -C printf
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re