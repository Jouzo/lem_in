NAME = lem-in

INC = -I includes
OBJDIR = obj

SRCS = 	main.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc -O3 -g
CFLAGS = -Wall -Werror -Wextra
PARSING = parsing/parsing.a
LIBFT = libft/libft.a

all: $(NAME)

$(PARSING):
	@make -C parsing

$(NAME): $(PARSING) $(LIBFT) $(OBJS) 
	$(CC) $(INC) $(CFLAGS) $(OBJS) $(LIBFT) $(PARSING) -o $(NAME)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C parsing
	-rm -rf $(OBJDIR)/*.o

fclean:clean
	@make fclean -C parsing
	-rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
