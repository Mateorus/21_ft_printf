# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 19:13:48 by gstiedem          #+#    #+#              #
#    Updated: 2019/01/17 23:52:52 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=libftprintf.a
SRCDIR:=src
OBJDIR:=obj
LIBDIR:=libft
INCLUDE:=include
SRC:=$(addprefix $(SRCDIR)/,ft_printf.c test.c)
OBJ:=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJ)
	ar -rc $(NAME) $^
	ranlib $(NAME)
	
clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ 

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

lib:
	make -C $(LIBDIR)

db: lib 
	$(CC) $(CFLAGC) $(SRC) -I$(INCLUDE)  main.c -g
