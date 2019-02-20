# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 14:06:40 by kcarrot           #+#    #+#              #
#    Updated: 2019/01/30 18:19:42 by kcarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 := checker
NAME2 := push_swap

FLAGS := -Wall -Werror -Wextra

LIB = libft/libft.a

SRC1 := checker_files/*.c
SRC2 := push_swap_files/*.c

OBJ1 := checker.o \
	list_operations.o \
	list_operations2.o \
	list_operations3.o \
	reading.o \
	sort.o

OBJ2 := find.o \
	is.o \
	list_operations2.o \
	sort.o \
	sort_large2.o \
	flags.o \
	list_operations.o \
	main.o \
	sort_large.o \
	tools_and_rrr.o

all: make_lib $(NAME1) $(NAME2)

make_lib:
	make -C libft/

$(NAME1): $(SRC1) inc/ps.h $(LIB)
	gcc $(FLAGS) -c checker_files/*.c -Iinc -Ilibft
	gcc -o $@ $(OBJ1) -Llibft -lft

$(NAME2): $(SRC2) inc/ps.h $(LIB)
	gcc $(FLAGS) -Iinc -Ilibft -c $(SRC2)	
	gcc -o $@ $(OBJ2) -Ilibft -Iinc -Llibft -lft

clean:
	rm -rf $(OBJ1) $(OBJ2)
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	rm -rf $(LIB)
re: fclean all