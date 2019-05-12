NAME = lem-in

INC_LIB = -I libft/includes
INC = -I includes
OBJDIR = obj

SRCS = 	main.c\
		list_edges.c\
		list_vertices.c\
		parsing.c\
		check_hash.c\
		get_source_sink.c\
		split.c\
		free.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc -O3 -g -Iincludes/
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

all: $(NAME) 

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re
clean:
	@make clean -C libft
	-rm -f $(OBJS)

fclean:clean
	@make fclean -C libft
	-rm -f $(NAME)

re: fclean all