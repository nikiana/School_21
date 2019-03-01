# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 19:04:47 by ffahey            #+#    #+#              #
#    Updated: 2019/02/22 08:37:58 by kcarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

vpath %.c src
vpath %.h inc
vpath %.o obj

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix obj/,$(notdir $(patsubst %.c,%.o,$(wildcard src/*.c))))

HEADERS = $(wildcard inc/*.h)

LIB = libft/libft.a

all: make_lib makedir $(NAME)

makedir:
	@mkdir -p obj

make_lib:
	make -C libft/

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $^ -o $@ -Iinc -Ilibft -Llibft -lft -Llibft -lftprintf

obj/%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c -g $< -o $@ -Iinc -Ilibft

clean:
	rm -rf obj/
	rm -rf libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re make_lib
