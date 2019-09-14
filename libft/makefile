# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:10:13 by jdescler          #+#    #+#              #
#    Updated: 2019/09/14 13:35:38 by mmovahhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJDIR = obj
SRCDIR = src

SRCS_NAMES = 		ft_abs.c\
	   				ft_atoi.c\
	   				ft_atoll.c\
	   				ft_isalnum.c\
	   				ft_bzero.c\
	   				ft_isalpha.c\
	   				ft_isascii.c\
	   				ft_isdigit.c\
	   				ft_isprint.c\
	   				ft_isint.c\
	   				ft_itoa.c\
	   				ft_lstadd.c\
	   				ft_lstcpy.c\
	   				ft_lstdel.c\
	   				ft_lstdelone.c\
	   				ft_lstiter.c\
	   				ft_lstmap.c\
	   				ft_lstnew.c\
	   				ft_memalloc.c\
	   				ft_memccpy.c\
	   				ft_memchr.c\
	   				ft_memcmp.c\
	   				ft_memcpy.c\
	   				ft_memdel.c\
	   				ft_memmove.c\
	   				ft_memset.c\
	   				ft_putchar.c\
	   				ft_putchar_fd.c\
	   				ft_putendl.c\
	   				ft_putendl_fd.c\
	   				ft_putnbr.c\
	   				ft_putnbr_fd.c\
	   				ft_putstr.c\
	   				ft_putstr_fd.c\
	   				ft_sizeofint.c\
	   				ft_strcasestr.c\
	   				ft_strcat.c\
	   				ft_strccpy.c\
	   				ft_strchr.c\
	   				ft_strclr.c\
	   				ft_strcmp.c\
	   				ft_strcpy.c\
	   				ft_strdel.c\
	   				ft_strdup.c\
	   				ft_strdup_until.c\
	   				ft_strequ.c\
	   				ft_striter.c\
	   				ft_striteri.c\
	   				ft_strjoin.c\
	   				ft_strlcat.c\
	   				ft_strlen.c\
	   				ft_strmap.c\
	   				ft_strmapi.c\
	   				ft_strncat.c\
	   				ft_strncmp.c\
	   				ft_strncpy.c\
	   				ft_strnequ.c\
	   				ft_strnew.c\
	   				ft_strnstr.c\
	   				ft_strrchr.c\
	   				ft_strrev.c\
	   				ft_strsplit.c\
	   				ft_strstr.c\
	   				ft_strsub.c\
	   				ft_strtocapitalize.c\
	   				ft_strtolower.c\
	   				ft_strtoupper.c\
	   				ft_strtrim.c\
	   				ft_tolower.c\
	   				ft_toupper.c\
	   				ft_word_count.c\
	   				ft_sqrt.c\
	   				get_next_line.c\
	   				multi_free.c\
	   				ft_atoll.c\
	   				ft_swap.c\
					ft_ceil.c\
	   				ft_insertion_sort.c\
	   				ft_print_arr.c\
	   				ft_min.c\

OBJS_NAMES = $(SRCS_NAMES:.c=.o)

SRCS = $(addprefix $(SRCDIR)/,$(SRCS_NAMES))
OBJS = $(addprefix $(OBJDIR)/,$(OBJS_NAMES))

CC = gcc
CFLAGS = -c -O2 -Wall -Werror -Wextra -Iincludes

all: $(OBJDIR) $(NAME)
	@:

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ $(CC) $(INC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Made libft !"

$(OBJ): $(SRCS)
	@ $(CC) $(CFLAGS) $(SRCS)

clean:
	@-rm -rf $(OBJDIR)
	@echo "Cleaned libft !"

fclean:
	@-rm -rf $(OBJDIR)
	@-rm -f $(NAME)
	@echo "Fcleaned libft !"

re: fclean all

.PHONY: all clean fclean re