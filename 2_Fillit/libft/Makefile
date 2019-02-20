#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 15:48:59 by ajon-hol          #+#    #+#              #
#    Updated: 2018/11/21 17:59:12 by ajon-hol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRCS = $(wildcard *.c)
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
clean:
	@/bin/rm -f $(OBJECTS)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
