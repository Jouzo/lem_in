NAME = lem-in

INC_LIB = -I libft/includes
INC = -I includes

SRCS = 	main.c\
		list_edges.c\
		list_vertices.c\
		parsing.c\

OBJS = $(SRCS:.c=.o)

CC = gcc -O3 -Iincludes/
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

all: $(NAME) 

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


.PHONY: clean fclean re
clean:
	@make clean -C libft
	-rm -f $(OBJS)

fclean:clean
	@make fclean -C libft
	-rm -f $(NAME)

re: fclean all