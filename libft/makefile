# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:10:13 by jdescler          #+#    #+#              #
#    Updated: 2019/05/12 14:58:36 by jdescler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_abs.c\
	   ft_atoi.c\
	   ft_bzero.c\
	   ft_isalnum.c\
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
	   

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Iincludes -c

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

.PHONY: clean
clean:
	-rm -f $(OBJS)

.PHONY: fclean
fclean:clean
	-rm -f $(NAME)

.PHONY: re
re: fclean all
