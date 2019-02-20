NAME = libft.a
SRC = *.c
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@ gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)  

clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
	
re: fclean all