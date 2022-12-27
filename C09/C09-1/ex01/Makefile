INCLUDES = includes
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
TARGET = libft.a

GCC = gcc
CFLAG = -Wall -Wextra -Werror

all : $(TARGET)

LIBC = ar rc

.c.o :
	$(GCC) $(CFLAG) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(TARGET) : $(OBJS)
		$(LIBC) $(TARGET) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY: all clean fclean re
