NAME = libparsing.a

INC_LIB = -I ../libft/includes
INC = -I includes
OBJDIR = obj

SRCS = 	list_edges.c\
		list_vertices.c\
		parsing.c\
		check_hash.c\
		get_source_sink.c\
		split.c\
		free.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc -O3
CFLAGS = -Wall -Werror -Wextra
LIBFT = ../libft/libft.a

all: directory $(NAME) 
	@:

$(NAME): $(LIBFT) $(OBJS)
	@ar rc $(NAME) $(OBJS) $(LIBFT)
	@ranlib $(NAME) 

directory: $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@ $(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	@-rm -f $(OBJS)

fclean:clean
	@-rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re directory
