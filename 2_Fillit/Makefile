
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 15:48:59 by kcarrot           #+#    #+#              #
#    Updated: 2018/12/11 16:14:26 by kcarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

vpath %.c src
vpath %.h inc
vpath %.o obj

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix obj/,$(notdir $(patsubst %.c,%.o,$(wildcard src/*.c))))

HEADERS = $(wildcard inc/*.h)

LIB = libft/libft.a

all: makedir make_lib $(NAME)

makedir:
	@mkdir -p obj

make_lib:
	@make -C libft/

$(NAME): $(OBJ) $(LIB)
	@gcc $(FLAGS) $^ -o $@ -Llibft -lft

obj/%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@ -Iinc -Ilibft 

clean:
	@rm -rf obj/
	@rm -rf libft/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re make_lib