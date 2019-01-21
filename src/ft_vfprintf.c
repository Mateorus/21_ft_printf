/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:11:12 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/21 23:42:26 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(int fd, const char *format, va_list ap)
{
	int			total;
	t_opt		opt;
	t_fp *fp;

	fp = (t_fp[1]){ft_putchar};
	total = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format += parse_flags(format, &opt);
			total += fp[opt.type](&opt, ap);
		}
		else
			((write(fd, format++, 1)) == -1) ? (total = -1) : total++;
	}
	return (total);
}
