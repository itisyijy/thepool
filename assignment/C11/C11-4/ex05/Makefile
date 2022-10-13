NAME = do-op
SRC = main.c ft_atoi.c ft_putnbr.c ft_strcmp.c operator.c 
GCC = gcc
CFALGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	$(GCC) $(CFLAGS) -o $(NAME) $(SRC)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
