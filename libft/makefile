# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:10:13 by jdescler          #+#    #+#              #
#    Updated: 2019/04/27 13:17:31 by jdescler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OPTION = -c -I /includes/libft.h

SRCS = ft_abs.c\
	   ft_atoi.c\
	   ft_atoll.c\
	   ft_bzero.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_itoa.c\
	   ft_lstadd.c\
	   ft_lstcpy.c\
	   ft_lstdel.c\
	   ft_lstdelone.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_lstnew.c\
	   ft_lstlen.c\
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
	   ft_stralloc.c\
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
	   ft_mega_malloc.c\

OBJS = ft_abs.o\
	   ft_atoi.o\
	   ft_atoll.o\
	   ft_bzero.o\
	   ft_isalnum.o\
	   ft_isalpha.o\
	   ft_isascii.o\
	   ft_isdigit.o\
	   ft_isprint.o\
	   ft_itoa.o\
	   ft_lstadd.o\
	   ft_lstcpy.o\
	   ft_lstdel.o\
	   ft_lstdelone.o\
	   ft_lstiter.o\
	   ft_lstmap.o\
	   ft_lstnew.o\
	   ft_lstlen.o\
	   ft_memalloc.o\
	   ft_memccpy.o\
	   ft_memchr.o\
	   ft_memcmp.o\
	   ft_memcpy.o\
	   ft_memdel.o\
	   ft_memmove.o\
	   ft_memset.o\
	   ft_putchar.o\
	   ft_putchar_fd.o\
	   ft_putendl.o\
	   ft_putendl_fd.o\
	   ft_putnbr.o\
	   ft_putnbr_fd.o\
	   ft_putstr.o\
	   ft_putstr_fd.o\
	   ft_sizeofint.o\
	   ft_stralloc.o\
	   ft_strcasestr.o\
	   ft_strcat.o\
	   ft_strccpy.o\
	   ft_strchr.o\
	   ft_strclr.o\
	   ft_strcmp.o\
	   ft_strcpy.o\
	   ft_strdel.o\
	   ft_strdup.o\
	   ft_strdup_until.o\
	   ft_strequ.o\
	   ft_striter.o\
	   ft_striteri.o\
	   ft_strjoin.o\
	   ft_strlcat.o\
	   ft_strlen.o\
	   ft_strmap.o\
	   ft_strmapi.o\
	   ft_strncat.o\
	   ft_strncmp.o\
	   ft_strncpy.o\
	   ft_strnequ.o\
	   ft_strnew.o\
	   ft_strnstr.o\
	   ft_strrchr.o\
	   ft_strrev.o\
	   ft_strsplit.o\
	   ft_strstr.o\
	   ft_strsub.o\
	   ft_strtocapitalize.o\
	   ft_strtolower.o\
	   ft_strtoupper.o\
	   ft_strtrim.o\
	   ft_tolower.o\
	   ft_toupper.o\
	   ft_word_count.o\
	   ft_mega_malloc.o\

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(OPTION) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	-rm -f $(OBJS)

fclean:clean
	-rm -f $(NAME)

re: fclean all
