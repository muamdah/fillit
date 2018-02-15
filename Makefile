# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muamdah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:34:06 by muamdah           #+#    #+#              #
#    Updated: 2018/02/15 13:00:27 by muamdah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDES = .

LIBFT = libft/libft.a

CC = gcc

SRC = ft_parse.c ft_open.c ft_map.c ft_map_suite.c main.c \

CFLAGS = -c -Wall -Wextra -Werror -I$(INCLUDES) -Ilibft

LFLAGS  = -L libft/ -lft

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(INCLUDES)
	$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
