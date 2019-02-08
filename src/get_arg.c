/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:28:35 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/08 23:46:06 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_length(char **format, t_opt *opt)
{
	if (**format == 'h' && *((*format) + 1) == 'h')
	{
		(*format)++;
		opt->length = 1;
	}
	else if (**format == 'h')
		opt->length = 2;
	else if (**format == 'l' && *((*format) + 1) == 'l')
	{
		(*format)++;
		opt->length = 3;
	}
	else if (**format == 'l')
		opt->length = 4;
	else if (**format == 'L')
		opt->length = 5;
	else if (**format == 'z')
		opt->length = 6;
	else if (**format == 'j')
		opt->length = 7;
	else
		return ;
	(*format)++;
}


void	cast_to_u(t_opt *opt)
{
	if (opt->type == 's')
	{
		opt->arg = (uintmax_t)opt->arg;
		return ;
	}
	if (opt->type == 'p')
	{
		opt->flags.hash = 1;
		opt->arg = (uintmax_t)opt->arg;
		return ;
	}
	opt->length == 0 ? opt->arg = (unsigned int)opt->arg : 0;
	opt->length == 1 ? opt->arg = (unsigned char)opt->arg : 0;
	opt->length == 2 ? opt->arg = (unsigned short)opt->arg : 0;
	opt->length == 3 ? opt->arg = (unsigned long long)opt->arg : 0;
	opt->length == 4 ? opt->arg = (unsigned long)opt->arg : 0;
	opt->length == 6 ? opt->arg = (size_t)opt->arg : 0;
	opt->length == 7 ? opt->arg = (uintmax_t)opt->arg : 0;
}

void	cast_to(t_opt *opt)
{
	opt->length == 0 ? opt->arg = (int)opt->arg : 0;
	opt->length == 1 ? opt->arg = (char)opt->arg : 0;
	opt->length == 2 ? opt->arg = (short)opt->arg : 0;
	opt->length == 3 ? opt->arg = (long long)opt->arg : 0;
	opt->length == 4 ? opt->arg = (long)opt->arg : 0;
	opt->length == 5 ? opt->arg = (long double)opt->arg : 0;
	opt->length == 6 ? opt->arg = (size_t)opt->arg : 0;
	opt->length == 7 ? opt->arg = (intmax_t)opt->arg : 0;
}

int		pick_func(t_opt *opt)
{
	int		i;
	char	type;

	i = 0;
	type = opt->type;
	type == '%' || type == 'c' ? i = 1 : 0;
	type == 's' ? i = 2 : 0;
	type == 'd' || type == 'i' || type == 'D' ? i = 3 : 0;
	type == 'u' || type == 'U' ? i = 4 : 0;
	type == 'x' || type == 'X' || type == 'p' ? i = 5 : 0;
	type == 'o' || type == 'O' ? i = 6 : 0;
	type == 'b' ? i = 7 : 0;
	if (type == 'U' || type == 'D' || type == 'O' || type == 'p' || type == 'F')
		opt->length = 4;
	if (type == 'x' || type == 'X' || type == 'o' || type == 'O' || type == 'u'
		|| type == 'p' || type == 's')
		cast_to_u(opt);
	else
		cast_to(opt);
	return (i);
}

int		get_arg(char **format, t_opt *opt, va_list ap)
{
	va_list	ap_copy;
	int		parameter;

	get_length(format, opt);
	opt->type = **format;
	(*format)++;
	parameter = opt->parameter;
	if (parameter != 0)
	{
		va_copy(ap_copy, ap);
		while (parameter--)
			opt->arg = va_arg(ap_copy, intmax_t);
		va_end(ap_copy);
	}
	else
		opt->arg = va_arg(ap, intmax_t);
	return (pick_func(opt));
}
