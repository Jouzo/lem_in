NAME = lem-in

INC = -Iincludes
OBJDIR = obj

SRCS = 	stringify.c\
		main.c\
		output.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc -O2 -g
CFLAGS = -Wall -Werror -Wextra
PARSING = parsing/libparsing.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
ALGO = algo/lib_algo.a

all: $(OBJDIR) $(NAME)
	@:

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@ $(CC) $(INC) $(CFLAGS) -c $< -o $@

FORCE: ;

$(LIBFT): FORCE
	@make -C libft

$(PARSING): FORCE
	@make -C parsing

$(ALGO): FORCE
	@make -C algo

$(PRINTF): FORCE
	@make -C ft_printf

$(NAME): $(LIBFT) $(PARSING) $(PRINTF) $(ALGO) $(OBJS) 
	@ $(CC) $(INC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(PARSING) $(ALGO) -o $(NAME)
	@echo "Made lem-in !"

$(OBJDIR)/%.o: %.c
	@ $(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C parsing
	@make clean -C algo
	@make clean -C ft_printf
	@make clean -C libft
	@-rm -rf $(OBJDIR)/*.o
	@echo "Cleaned lem-in !"	

fclean:
	@make fclean -C parsing
	@make fclean -C algo
	@make fclean -C ft_printf
	@make fclean -C libft
	@-rm -rf $(OBJDIR)/*.o
	@-rm -f $(NAME)
	@echo "Fcleaned lem-in !"	

re: fclean all

.PHONY: clean fclean re
