# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 20:44:32 by kilkim            #+#    #+#              #
#    Updated: 2019/09/05 18:59:44 by kilkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INC =  srcs/fillit.h

SRC = srcs/board.c srcs/fillit.c srcs/free.c srcs/get_map_size.c \
	  srcs/is_valid.c srcs/need_for_link.c srcs/node_link.c

OBJ = *.o

all: objs $(NAME)

objs:
	@mkdir -p objs

FLAGS = -Wall -Wextra -Werror

$(NAME):
		@make -C libft
		@gcc $(FLAGS) -I $(INC) -c $(SRC)
		@gcc $(OBJ) -L libft/ -lft -o $(NAME)
		@mv *.o objs

clean:
		@make -C libft/ clean
		@rm -rf objs

fclean:
		@make -C libft/ fclean
		@rm -f $(NAME)
		@rm -rf objs

re: fclean all
