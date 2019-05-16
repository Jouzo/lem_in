NAME = lib_algo.a

INC_LIB = -I ../libft/includes
INC = -I includes
OBJDIR = obj

SRCS = 	bfs.c\
		queue_array.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc -O3 -g
CFLAGS = -Wall -Werror -Wextra
LIBFT = ../libft/libft.a

all: directory $(NAME) 

$(LIBFT):
	@make -C ../libft

$(NAME): $(LIBFT) $(OBJS)
	ar rc $(NAME) $(OBJS) $(LIBFT)
	ranlib $(NAME) 

directory: $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(INC) $(INC_LIB) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ../libft
	-rm -f $(OBJS)

fclean:clean
	@make fclean -C ../libft
	-rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re directory
