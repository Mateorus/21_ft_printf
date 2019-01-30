/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 22:10:24 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 22:36:23 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, t_opt *opt)
{
	uint64_t	tmp;
	uint64_t	num;
	int			i;

	num = opt->arg;
	!num ? buf[0] = '0' : 0;
	!num && !opt->precision && !opt->flags.hash ? buf[0] = 0 : 0;
	i = 1;
	tmp = num;
	while (tmp >>= 3)
		i++;
	while (num)
	{
		tmp = 0x7 & num;
		buf[--i] = tmp + '0';
		num >>= 3;
	}
}

static void	padding(int fd, t_opt *opt, int *total, int len)
{
	int 		width;
	char		c[1];

	c[0] = ' ';
	width = opt->width;
	(opt->precision > len) ? (width -= opt->precision) : (width -= len);
	if (opt->flags.hash && opt->arg)
		width--;
	if (opt->flags.zero && opt->precision < 0 && !opt->flags.minus)
		c[0] = '0';
	while (width-- > 0)
		(write(fd, c, 1) != -1) ? (*total)++ : (*total = -1);
}

static void	prepend(int fd, t_opt *opt, int *total, int len)
{
	int		dif;

	dif = opt->precision - len;
	if (opt->flags.hash && !opt->flags.zero && opt->arg)
		(write(fd, "0", 1) != -1) ? (*total)++ : (*total = -1);
	while(dif-- > 0)
		(write(fd, "0", 1) != -1) ? (*total)++ : (*total = -1);
}

void	ft_putnbr_base8(int fd, t_opt *opt, int *total)
{
	char		buf[BUF];
	int			i;
	int			len;

	ft_bzero(buf, BUF);
	itoa(buf, opt);
	len = ft_strlen(buf);
	if (opt->flags.hash && opt->flags.zero && opt->arg)
		(write(fd, "0", 1) != -1) ? (*total)++ : (*total = -1);
	(opt->width &&!opt->flags.minus) ? padding(fd, opt, total, len) : 0;
	prepend(fd, opt, total, len);
	i = -1;
	while (buf[++i])
		(write(fd, &buf[i], 1) != -1) ? (*total)++ : (*total = -1);
	(opt->width && opt->flags.minus) ? padding(fd, opt, total, len) : 0;
}
