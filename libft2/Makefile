# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 14:03:12 by nsabbah           #+#    #+#              #
#    Updated: 2016/11/29 15:39:49 by nsabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_SRC = ./src/
HEADER = ./includes/
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = $(PATH_SRC)ft_strcat.c $(PATH_SRC)ft_strncat.c  \
	$(PATH_SRC)ft_strncpy.c $(PATH_SRC)ft_strcpy.c $(PATH_SRC)ft_strdup.c \
	$(PATH_SRC)ft_strndup.c $(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_strlcat.c \
	$(PATH_SRC)ft_memset.c $(PATH_SRC)ft_bzero.c $(PATH_SRC)ft_memcpy.c \
	$(PATH_SRC)ft_memccpy.c $(PATH_SRC)ft_memmove.c \
	$(PATH_SRC)ft_memchr.c $(PATH_SRC)ft_memcmp.c $(PATH_SRC)ft_strchr.c \
	$(PATH_SRC)ft_strrchr.c $(PATH_SRC)ft_strstr.c $(PATH_SRC)ft_strnstr.c \
	$(PATH_SRC)ft_strcmp.c $(PATH_SRC)ft_strncmp.c $(PATH_SRC)ft_isalpha.c \
	$(PATH_SRC)ft_isalpha.c $(PATH_SRC)ft_isdigit.c $(PATH_SRC)ft_isalnum.c \
	$(PATH_SRC)ft_isascii.c $(PATH_SRC)ft_isprint.c $(PATH_SRC)ft_toupper.c \
	$(PATH_SRC)ft_tolower.c $(PATH_SRC)ft_atoi.c $(PATH_SRC)ft_memalloc.c \
	$(PATH_SRC)ft_memdel.c $(PATH_SRC)ft_strnew.c $(PATH_SRC)ft_strdel.c \
	$(PATH_SRC)ft_strclr.c $(PATH_SRC)ft_striter.c $(PATH_SRC)ft_putchar.c \
	$(PATH_SRC)ft_putstr.c $(PATH_SRC)ft_putendl.c $(PATH_SRC)ft_putnbr.c \
	$(PATH_SRC)ft_putchar_fd.c $(PATH_SRC)ft_putstr_fd.c \
	$(PATH_SRC)ft_putendl_fd.c $(PATH_SRC)ft_putnbr_fd.c \
	$(PATH_SRC)ft_striteri.c $(PATH_SRC)ft_strmap.c $(PATH_SRC)ft_strmapi.c \
	$(PATH_SRC)ft_strequ.c $(PATH_SRC)ft_strsub.c $(PATH_SRC)ft_strjoin.c \
	$(PATH_SRC)ft_strtrim.c $(PATH_SRC)ft_strsplit.c $(PATH_SRC)ft_strnequ.c \
	$(PATH_SRC)ft_itoa.c $(PATH_SRC)ft_lstnew.c $(PATH_SRC)ft_lstdelone.c \
	$(PATH_SRC)ft_lstdel.c $(PATH_SRC)ft_lstadd.c $(PATH_SRC)ft_lstiter.c \
	$(PATH_SRC)ft_lstmap.c


OBJ = ft_strcat.o  ft_strcpy.o  ft_strdup.o ft_strndup.o ft_strlen.o \
	ft_strncpy.o ft_strncat.o ft_strlcat.o ft_memset.o ft_bzero.o ft_memcpy.o \
	ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strchr.o \
	ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_isalpha.o \
	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	ft_toupper.o ft_tolower.o ft_atoi.o ft_memalloc.o ft_memdel.o \
	ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_putchar.o ft_putstr.o \
	ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
	ft_putnbr_fd.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
	ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_strnequ.o ft_itoa.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
