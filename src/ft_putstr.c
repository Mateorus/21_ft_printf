/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:04:08 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 11:42:34 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	padding(int fd, t_opt *opt, int	*total)
{
	int	width;
	int	len;

	len = ft_strlen((char*)opt->arg);
	if ((opt->precision > len || !len) || opt->precision == -1)
		width = opt->width - len;
	else
		width = opt->width - opt->precision;
	while (width-- > 0)
		(write(fd, " ", 1) != -1) ? (*total)++ : (*total = -1);
}

void		ft_putstr(int fd, t_opt *opt, int *total)
{
	char	*s;
	int		precision;

	precision = opt->precision;
	s = "(null)";
	if (!opt->arg)
		opt->arg = (uint64_t)s;
	s = (char*)opt->arg;
	(opt->width && !opt->flags.minus) ? padding(fd, opt, total) : 0;
	while(*s && *total != -1 && precision--)
	{
		(write(fd, s, 1) != -1) ? (*total)++ : (*total = -1);
		s++;
	}
	(opt->width && opt->flags.minus) ? padding(fd, opt, total) : 0;
}
