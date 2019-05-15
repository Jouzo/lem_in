NAME = lem-in

INC = -Iincludes
OBJDIR = obj

SRCS = 	main.c\
		stringify.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc -O3 -g
CFLAGS = -Wall -Werror -Wextra
PARSING = parsing/libparsing.a
LIBFT = libft/libft.a


all: $(NAME)

FORCE: ;

$(PARSING): FORCE
	@make -C parsing

$(NAME): $(PARSING) $(LIBFT) $(OBJS) 
	$(CC) $(INC) $(CFLAGS) $(OBJS) $(LIBFT) $(PARSING) -o $(NAME)

$(OBJDIR)/%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C parsing
	-rm -rf $(OBJDIR)/*.o

fclean:clean
	@make fclean -C parsing
	-rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
