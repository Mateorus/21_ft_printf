/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:43:11 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/21 13:06:20 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// DELETE!!!!! stdio.h !!!!!!
# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF			129

/*
* *_______________________________TYPES___________________________________
*/
typedef struct	s_flags
{
	uint8_t		minus;
	uint8_t		plus;
	uint8_t		space;
	uint8_t		zero;
	uint8_t		hash;
}				t_flags;
typedef struct	s_opt
{
	uint8_t		parameter;
	t_flags		flags;
	int			width;
	int			precision;
	uint8_t		length;
	char		type;
	intmax_t	arg;
	long double	float_arg;

}				t_opt;
typedef int		(*t_fp)(char**, int, t_opt*);

/*
* *_______________________________SRC___________________________________
*/
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vfprintf(int fd, char *format, va_list ap);
int				parser(char **format, t_opt *opt, va_list ap);
int				get_arg(char **format, t_opt *opt, va_list ap);
int				skip(char **res, int res_len, t_opt *opt);
int				ft_putchar(char **res, int res_len, t_opt *opt);
int				ft_putstr(char **res, int res_len, t_opt *opt);
int				ft_putnbr(char **res, int res_len, t_opt *opt);
int				ft_putunbr(char ** res, int res_len, t_opt *opt);
int				ft_putnbr_base16(char **res, int res_len, t_opt *opt);
int				ft_putnbr_base8(char **res, int res_len, t_opt *opt);
int				ft_putnbr_base2(char **res, int res_len, t_opt *opt);
int				ft_putfloat(char **res, int res_len, t_opt *opt);

/*
* *_______________________________UTIL___________________________________
*/
int				ft_strncat(char **s1, char *s2, size_t len1, size_t len2);
size_t			ft_strlen(const char *s);
char			*ft_strchr(char *s, char c);
void			ft_strncpy(char *dst, char *src, int n);
void			ft_bzero(void *s, size_t n);
void			ft_revstr(char *s, size_t len);
void			ft_ftoa(t_opt *opt, char **s);

#endif
