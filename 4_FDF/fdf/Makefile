# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 16:33:34 by kcarrot           #+#    #+#              #
#    Updated: 2019/01/16 14:56:50 by kcarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = get_map.c
SRC += drawing_tools.c
SRC += scale.c
SRC += structs.c
SRC += events.c
SRC += rotation.c
SRC += movement.c
SRC += main.c
OBJECTS = *.o
FLAGS = -Wall -Werror -Wextra
FRAMES = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@ make -C libft fclean && make -C libft
	@ gcc $(FLAGS) -L./libft -lft -L. -lmlx -o $(NAME) $(SRC) $(FRAMES)
clean:
	@ /bin/rm -f $(OBJECTS)
	@ make -C libft clean
fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C libft fclean
re: fclean all