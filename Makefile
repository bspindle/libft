# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bspindle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:32:49 by bspindle          #+#    #+#              #
#    Updated: 2017/12/19 13:21:37 by bspindle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

SRC_PATH = .

OBJ_PATH = .

CC = gcc 

CPP = -c

CFLAGS = -Wall -Werror -Wextra

SRC_NAME = ft_putchar.c 	\
	   ft_putstr.c 		\
	   ft_strcmp.c		\
	   ft_strlen.c 		\
	   ft_strdup.c 		\
	   ft_memalloc.c	\
	   ft_memdel.c		\
	   ft_strnew.c		\
	   ft_strdel.c		\
	   ft_strclr.c		\
	   ft_striter.c		\
	   ft_striteri.c	\
	   ft_strmap.c		\
	   ft_strmapi.c		\
	   ft_strequ.c		\
	   ft_strncmp.c		\
	   ft_strnequ.c		\
	   ft_strsub.c		\
	   ft_strcat.c		\
	   ft_strjoin.c		\
	   ft_strtrim.c		\
	   ft_strsplit.c	\
	   ft_itoa.c		\
	   ft_putendl.c		\
	   ft_putnbr.c		\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c 	\
	   ft_putnbr_fd.c	\
	   ft_memset.c		\
	   ft_bzero.c		\
	   ft_memcpy.c		\
	   ft_memccpy.c		\
	   ft_memmove.c 	\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_strcpy.c		\
	   ft_strncpy.c		\
	   ft_strncat.c		\
	   ft_strlcat.c		\
	   ft_strchr.c		\
	   ft_strrchr.c		\
	   ft_strstr.c		\
	   ft_strnstr.c		\
	   ft_atoi.c		\
	   ft_isdigit.c		\
	   ft_isalpha.c		\
	   ft_isalnum.c		\
	   ft_isascii.c		\
	   ft_isprint.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_lstnew.c		\
	   ft_lstdelone.c	\
	   ft_lstdel.c		\
	   ft_lstadd.c		\
	   ft_lstiter.c		\
	   ft_lstmap.c		\
	   ft_sqrt.c		\
	   ft_lstcpy.c		\
	   ft_pow.c			\
	   ft_factorial.c	\
	   ft_isprime.c		\
	   ft_nextprime.c	\
	   ft_strcut.c		\
	   ft_min.c			\
	   ft_lstdeloneof.c	\
	   ft_putlst.c		\
	   ft_lstdelfirst.c	\
	   ft_strnjoin.c	\
	   ft_strnchr.c		\
	   ft_del_chartab.c	\
	   get_next_line.c	\
	   get_next_wyw.c	\
	   get_file.c

INCLUDE = libft.h get_next_line.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs  $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir $(OBJ_PATH) 2> /dev/null
	$(CC)  $(CFLAGS)  -o $@ -c $<
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

