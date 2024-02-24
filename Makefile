NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

INC = -Iincludes/ -Ilibft/ -Iprintf/

LIBS = -Llibft -Lprintf -lft

SRCS = *.c 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	cd libft; make
	cd printf; make
	$(CC) *.c libft/libft.a printf/libftprintf.a  -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean :
	rm -rf $(OBJS) $(ARCHIVE) *.dSYM a.out *.o
	cd libft && $(MAKE) clean
	cd printf && $(MAKE) clean

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re