/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:43:11 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/21 23:41:37 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

enum				e_arg_type{c, s, d, i = 2, u = 2, };
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
	uint8_t			width;
	uint8_t			precision;
	enum e_arg_type	type;
}					t_opt;
typedef int			(*t_fp)(t_opt*, va_list);

int					ft_printf(const char *format, ...);
int					ft_vfprintf(int fd, const char *format, va_list ap);
int					parse_flags(const char *format, t_opt *opt);
int					ft_putchar(t_opt *opt, va_list ap);
void				ft_bzero(void *s, size_t n);

#endif
