# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 12:26:31 by tknibbe           #+#    #+#              #
#    Updated: 2023/07/26 15:51:30 by tknibbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	tictactoe
SRC		=	main.c \
			utils.c \
			win_check.c

OBJ		=	$(SRC:%.c=obj/%.o)
FSAN	=	-fsanitize=address

obj/%.o : src/%.c
	mkdir -p obj
	cc -c $^ -o $@

all: $(OBJ)
	gcc $(FSAN) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
	rm -rf obj
re: fclean all