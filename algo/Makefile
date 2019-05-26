NAME = lib_algo.a

INC_LIB = -I ../libft/includes
INC = -I includes
OBJDIR = obj

SRCS = 	bfs.c\
		algo.c\
		queue_array.c\
		list_path.c\
		list_flow.c\
		free.c\
		path.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc #-fsanitize=address
CFLAGS = -Wall -Werror -Wextra
LIBFT = ../libft/libft.a

all: directory $(NAME) 
	@:
$(NAME): $(LIBFT) $(OBJS)
	@ar rc $(NAME) $(OBJS) $(LIBFT)
	@ranlib $(NAME) 

directory: $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@ $(CC) $(INC) $(INC_LIB) $(CFLAGS) -c $< -o $@

clean:
	@-rm -rf $(OBJDIR)

fclean:clean
	@-rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re directory
