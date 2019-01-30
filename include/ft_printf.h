/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:43:11 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 22:17:20 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_OF_TYPES	22
#define NUM_OF_FUNC		7
#define BUF				30

typedef struct		s_flags
{
	uint8_t			minus;
	uint8_t			plus;
	uint8_t			space;
	uint8_t			zero;
	uint8_t			hash;
}					t_flags;
typedef struct		s_opt
{
	uint8_t			parameter;
	t_flags			flags;
	int				width;
	int				precision;
	uint8_t			length;
	char			type;
	uint64_t		arg;
}					t_opt;
typedef void		(*t_fp)(int, t_opt*, int*);

int					ft_printf(const char *format, ...);
int					ft_vfprintf(int fd, char *format, va_list ap);
void				ft_bzero(void *s, size_t n);
int					parser(char **format, t_opt *opt, va_list ap);
int					get_arg(char **format, t_opt *opt, va_list ap);
void				skip(int fd, t_opt *opt, int *total);
void				ft_putchar(int fd, t_opt *opt, int *total);
void				ft_putstr(int fd, t_opt *opt, int *total);
size_t				ft_strlen(const char *s);
void				ft_putnbr(int fd, t_opt *opt, int *total);
void				ft_putunbr(int f, t_opt *opt, int *total);
void				ft_putnbr_base16(int f, t_opt *opt, int *total);
void				ft_putnbr_base8(int f, t_opt *opt, int *total);

#endif
