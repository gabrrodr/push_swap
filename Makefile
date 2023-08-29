# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:23:57 by gabrrodr          #+#    #+#              #
#    Updated: 2023/08/29 17:22:38 by gabrrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

NAME = push_swap

SRC =	check.c \
		frees.c \
		init.c \
		lists.c \
		main.c \
		utils.c \
		ops.c \
		sort.c \

OBJ_SRC = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft

$(NAME): $(OBJ_SRC) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(LIBFT) -o $(NAME)


clean:
	$(MAKE) clean -C ./libft
	@$(RM) $(OBJ_SRC) 

fclean: clean
	@$(RM) $(LIBFT) $(NAME)
	
re: fclean all