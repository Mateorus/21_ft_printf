/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:28:35 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/09 17:38:13 by gstiedem         ###   ########.fr       */
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

void	cast_to(t_opt *opt)
{
	char	t;

	t = opt->type;
	t == 'p' ? opt->flags.hash = 1 : 0;
	if (t == 'b' || t == 's' || t == 'p')
		return ;
	if (t == 'x' || t == 'X' || t == 'o' || t == 'O' || t == 'u' || t == 'U')
	{
		opt->length == 0 ? opt->arg = (unsigned int)opt->arg : 0;
		opt->length == 1 ? opt->arg = (unsigned char)opt->arg : 0;
		opt->length == 2 ? opt->arg = (unsigned short)opt->arg : 0;
		opt->length == 3 ? opt->arg = (unsigned long long)opt->arg : 0;
		opt->length == 4 ? opt->arg = (unsigned long)opt->arg : 0;
		opt->length == 6 ? opt->arg = (size_t)opt->arg : 0;
		opt->length == 7 ? opt->arg = (uintmax_t)opt->arg : 0;
		return ;
	}
	opt->length == 0 ? opt->arg = (int)opt->arg : 0;
	opt->length == 1 ? opt->arg = (char)opt->arg : 0;
	opt->length == 2 ? opt->arg = (short)opt->arg : 0;
	opt->length == 3 ? opt->arg = (long long)opt->arg : 0;
	opt->length == 4 ? opt->arg = (long)opt->arg : 0;
	opt->length == 6 ? opt->arg = (size_t)opt->arg : 0;
	opt->length == 7 ? opt->arg = (intmax_t)opt->arg : 0;
}

int		pick_func(t_opt *opt)
{
	int		i;
	char	type;

	i = 0;
	if (opt->type == 'e' || opt->type == 'f')
		return (8);
	type = opt->type;
	type == '%' || type == 'c' ? i = 1 : 0;
	type == 's' ? i = 2 : 0;
	type == 'd' || type == 'i' || type == 'D' ? i = 3 : 0;
	type == 'u' || type == 'U' ? i = 4 : 0;
	type == 'x' || type == 'X' || type == 'p' ? i = 5 : 0;
	type == 'o' || type == 'O' ? i = 6 : 0;
	type == 'b' ? i = 7 : 0;
	if (type == 'U' || type == 'D' || type == 'O')
		opt->length = 4;
	return (i);
}

int		get_arg(char **format, t_opt *opt, va_list ap)
{
	int		func;

	get_length(format, opt);
	opt->type = *(*format)++;
	func = pick_func(opt);
	if (func == 8 || (func == 7 && (opt->length == 4 || opt->length == 5)))
	{
		if (opt->length == 5)
			opt->float_arg = va_arg(ap, long double);
		else
			opt->float_arg = va_arg(ap, double);
		return (func);
	}
	if (!func || opt->type == '%')
		return (func);
	opt->arg = va_arg(ap, intmax_t);
	cast_to(opt);
	return (func);
}
