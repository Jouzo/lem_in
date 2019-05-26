# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:10:13 by jdescler          #+#    #+#              #
#    Updated: 2019/05/26 18:40:56 by jdescler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJDIR = obj

SRCS =	add_option.c\
		add_option2.c\
		add_option3.c\
		conversion.c\
		conversion2.c\
		conversion3.c\
		init_parse.c\
		init_parse2.c\
		init_parse3.c\
		unicode.c\
		check_buf.c\
		big_option.c\
		option_string.c\
		option_string2.c\
		option_double.c\
		ft_bzero.c\
		ft_itoc.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_printstr.c\
		ft_strchr.c\
		ft_strlen.c\
		ft_strrev.c\
		ft_strcmp.c\
		ft_printf.c\
		ft_all_toa_base.c\
		ft_all_toa_base2.c\
		ft_dtoa.c\
		ft_dtoa2.c\

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC = gcc
CFLAGS = -c -O3 -Wall -Werror -Wextra -Iincludes

all: $(OBJDIR) $(NAME)
	@:

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@ $(CC) $(INC) $(INC_LIB) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Made printf !"

clean:
	@-rm -rf $(OBJDIR)
	@echo "Cleaned printf !"

fclean:
	@-rm -rf $(OBJDIR)
	@-rm -f $(NAME)
	@echo "Fcleaned printf !"

re: fclean all

.PHONY: clean fclean re all
