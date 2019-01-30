/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:11:12 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 23:36:40 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(int fd, char *format, va_list ap)
{
	int			total;
	t_opt		opt;
	t_fp		*fp;

	fp = (t_fp[NUM_OF_FUNC]){skip, ft_putchar, ft_putstr, ft_putnbr,
		ft_putunbr, ft_putnbr_base16, ft_putnbr_base8};
	total = 0;
	while (*format && total != -1)
	{
		if (*format == '%')
			fp[parser(&format, &opt, ap)](fd, &opt, &total);
		else
			((write(fd, format++, 1)) == -1) ? (total = -1) : total++;
	}
	return (total);
}
