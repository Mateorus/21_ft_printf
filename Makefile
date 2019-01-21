# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 19:13:48 by gstiedem          #+#    #+#              #
#    Updated: 2019/01/21 23:23:35 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=libftprintf.a
SRCDIR:=src
OBJDIR:=obj
LIBDIR:=libft
INCLUDE:=include
SRC:=$(addprefix $(SRCDIR)/,\
	ft_printf.c ft_vfprintf.c ft_putchar.c parse_flags.c ft_bzero.c)
OBJ:=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ 

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

db:
	$(CC) $(CFLAGC) $(SRC) -I$(INCLUDE)  main.c -g
