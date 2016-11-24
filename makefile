# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewallner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 16:30:18 by ewallner          #+#    #+#              #
#    Updated: 2016/11/22 18:12:59 by ewallner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= get_next_line

SRC=	main.c\
			get_next_line.c\


OBJ= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I./libft
LIBLINK= -L./libft -lft

SRCDIR= ./src/
INCDIR= ./includes/
OBJDIR= ./obj/

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): obj libft $(OBJ)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

remlib:
	rm -rf $(LIBFT)

remoblib:
	make fclean -C ./libft/

clean: remoblib
	rm -rf $(OBJDIR)

fclean: clean remlib
	rm -rf $(NAME)

re: fclean all
