# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 19:13:48 by gstiedem          #+#    #+#              #
#    Updated: 2019/03/12 14:00:03 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=libftprintf.a
SRCDIR:=src
UTILDIR=util
OBJDIR:=obj
LIBDIR:=libft
INCLUDE:=include
SRC:=$(addprefix $(SRCDIR)/,\
	ft_printf.c ft_dprintf.c ft_sprintf.c ft_vfprintf.c ft_putchar.c parser.c\
	get_arg.c skip.c ft_putstr.c ft_putnbr.c ft_putnbr_base16.c ft_putunbr.c\
	ft_putnbr_base8.c ft_putnbr_base2.c ft_putfloat.c ft_ftoa.c f_conversion.c\
	e_conversion.c get_whole_part.c get_frac_part.c)
UTIL=$(addprefix $(UTILDIR)/,\
	ft_bzero.c ft_strlen.c ft_strchr.c ft_strncat.c ft_strncpy.c ft_revstr.c\
	 ft_strcpy.c assert_malloc.c)
OBJ:=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJ:=$(OBJ) $(patsubst $(UTILDIR)/%.c, $(OBJDIR)/%.o, $(UTIL))
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

$(OBJDIR)/%.o: $(UTILDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ 

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

db:
	$(CC) $(CFLAGC) $(SRC) $(UTIL) -I$(INCLUDE)  main.c -g
