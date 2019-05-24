NAME = lem-in

INC = -Iincludes
OBJDIR = obj

SRCS = 	main.c\
		stringify.c\
		output.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc -O2 -g -fsanitize=address
CFLAGS = -Wall -Werror -Wextra
PARSING = parsing/libparsing.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
ALGO = algo/lib_algo.a

all: $(NAME)

FORCE: ;

$(PARSING): FORCE
	@make -C parsing

$(ALGO): FORCE
	@make -C algo

$(PRINTF): FORCE
	@make -C ft_printf

$(NAME): $(PARSING) $(LIBFT) $(PRINTF) $(ALGO) $(OBJS) 
	$(CC) $(INC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(PARSING) $(ALGO) -o $(NAME)

$(OBJDIR)/%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C parsing
	@make clean -C algo
	@make clean -C ft_printf
	-rm -rf $(OBJDIR)/*.o

fclean:clean
	@make fclean -C parsing
	@make fclean -C algo
	@make fclean -C ft_printf
	-rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
