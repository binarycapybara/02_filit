# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/07/10 15:21:45 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = fillit

HEADERS = fillit.h\
	libft/libft.h

OBJ = main.o\
	ft_box.o\
	ft_one_sh.o

SRC = main.c\
	ft_box.c\
	ft_one_sh.c

all: $(NAME)

$(NAME):
	@$(CC) -c -I $(HEADERS) $(CFLAGS) $(SRC)
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

