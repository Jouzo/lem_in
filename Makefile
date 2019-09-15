NAME = lem-in

INC = -Iincludes
OBJDIR = obj
SRCDIR = src
LIBFTDIR = libft
LIBINC = -Ilibft/includes

SRCS_NAMES = 	main.c\
				output.c\
				path.c\
				print_map.c\
				print_output.c\
				ants.c\
				algo.c\
				bfs.c\
				free_algo.c\
				list_flow.c\
				list_path.c\
				find_path.c\
				queue.c\
				reverse.c\
				check_hash.c\
				free_parsing.c\
				get_source_sink.c\
				list_edges.c\
				list_vertices.c\
				parsing.c\
				split.c\
				stringify.c\
				check_path.c\
				get_yield.c\
				get_path.c\

OBJS_NAMES = $(SRCS_NAMES:.c=.o)

SRCS = $(addprefix $(SRCDIR)/,$(SRCS_NAMES))
OBJS = $(addprefix $(OBJDIR)/,$(OBJS_NAMES))

CC = gcc 
CFLAGS = -O2 -g -Wall -Werror -Wextra

LIBFT = libft/libft.a

all: $(OBJS) $(NAME)


$(LIBFT): FORCE
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(INC) $(LIBINC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Made lem-in !"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(INC) $(LIBINC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@echo "Cleaned lem-in !"	

fclean:
	@make fclean -C libft
	@-rm -f $(NAME)
	@echo "Fcleaned lem-in !"	

re: fclean all

.PHONY: clean fclean re all

FORCE: 