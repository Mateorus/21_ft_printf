/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 00:07:10 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 23:29:11 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_parameter(char **format, t_opt *opt)
{
	int		place;
	char	*s;

	s = *format;
	place = 0.0;
	while (*s > '0' && *s <= '9')
	{
		place *= 10;
		place += *s++ - '0';
	}
	if (*s == '$')
	{
		opt->parameter = place;
		(*format) += (++s - (*format));
	}
}

void	get_flags(char **format, t_opt *opt)
{
	char	*s;

	s = *format;
	while (*s == '-' || *s == '0' || *s == '+' || *s == ' ' || *s == '#')
	{
		if (*s == '-')
			opt->flags.minus = 1;
		else if (*s == '0')
			opt->flags.zero = 1;
		else if (*s == '+')
			opt->flags.plus = 1;
		else if (*s == ' ')
			opt->flags.space = 1;
		else if (*s == '#')
			opt->flags.hash = 1;
		s++;
	}
	(*format) += (s - (*format));
}

void	get_width(char **format, t_opt *opt, va_list ap)
{
	char	*s;
	int		width;

	s = *format;
	if (*s == '*')
	{
		opt->width = va_arg(ap, int);
		(*format)++;
		return ;
	}
	width = 0.0;
	while (*s >= '0' && *s <= '9')
	{
		width *= 10;
		width += *s++ - '0';
	}
	opt->width = width;
	(*format) += (s - (*format));
}

void	get_precision(char **format, t_opt *opt, va_list ap)
{
	char	*s;
	int		precision;

	s = *format;
	if (*s++ != '.')
	{
		opt->precision = -1;
		return ;
	}
	if (*s == '*')
	{
		opt->precision = va_arg(ap, int);
		(*format) += 2;
		return ;
	}
	precision = 0.0;
	while (*s >= '0' && *s <= '9')
	{
		precision *= 10;
		precision += *s++ - '0';
	}
	opt->precision = precision;
	(*format) += (s - (*format));
}

int		parser(char **format, t_opt *opt, va_list ap)
{
	char	*copy;
	int		i;

	(*format)++;
	copy = *format;
	ft_bzero(opt, sizeof(*opt));
	get_parameter(&copy, opt);
	get_flags(&copy, opt);
	get_width(&copy, opt, ap);
	get_precision(&copy, opt, ap);
	if (!(i = get_arg(&copy, opt, ap)))
		return (0);
	(*format) += copy - (*format);
	return (i);
}
