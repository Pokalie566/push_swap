# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeboose <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 12:11:02 by adeboose          #+#    #+#              #
#    Updated: 2024/10/19 12:11:05 by adeboose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

INC_DIR = includes
INCS = -I ./$(INC_DIR) -I lib/libft/$(INC_DIR)

LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a

SRC_PATH = src/
OBJ_PATH = obj/

SRC	=	input_check.c \
		input_check_utils.c \
		initialization.c \
		stack.c \
		swap.c \
		push.c \
		main.c \
		rotate.c \
		reverse_rotate.c \
		sort_tiny.c \
		sort.c \
		position.c \
		cost.c \
		do_move.c \
		utils.c \
		ft_strtok.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

$(LIBFT):
	make --no-print-directory -C $(LIBFT_DIR) -s -j all

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $@ $(LIBFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	make --no-print-directory -C $(LIBFT_DIR) -s -j clean

fclean: clean
	rm -f $(NAME)
	make --no-print-directory -C $(LIBFT_DIR) -s -j fclean

re: fclean all

.PHONY: all clean fclean re
