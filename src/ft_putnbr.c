/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:32:46 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 14:53:24 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, uint64_t num, int precision)
{
	int64_t	tmp;
	int		i;

	!num ? buf[0] = '0' : 0;
	!num && !precision ? buf[0] = 0 : 0;
	i = 1;
	tmp = num;
	while (tmp /= 10)
		i++;
	tmp = num;
	if ((uint64_t)tmp == -9223372036854775808U)
	{
		buf[--i] = '8';
		tmp /= 10;
	}
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		buf[--i] = tmp % 10 + '0';
		tmp /= 10;
	}
}

static void	padding(int fd, t_opt *opt, int *total, int len)
{
	int 	width;
	int64_t	num;
	char	c[1];

	c[0] = ' ';
	num = opt->arg;
	width = opt->width;
	(opt->precision > len) ? (width -= opt->precision) : (width -= len);
	if (opt->flags.space && !opt->flags.plus && num >= 0)
		width--;
	if (opt->flags.plus && num >= 0)
		width--;
	if (num < 0)
		width--;
	if (opt->flags.zero && !opt->flags.minus && opt->precision < 0)
		c[0] = '0';
	while (width-- > 0)
		(write(fd, c, 1) != -1) ? (*total)++ : (*total = -1);
}

static void	prepend(int fd, t_opt *opt, int *total, int len)
{
	int64_t	num;
	int		dif;

	num = opt->arg;
	dif = opt->precision - len;
	if (opt->flags.space && !opt->flags.plus && num >= 0)
		(write(fd, " ", 1) != -1) ? (*total)++ : (*total = -1);
	if (num >= 0 && !opt->flags.zero && opt->flags.plus)
		(write(fd, "+", 1) != -1) ? (*total)++ : (*total = -1);
	if (num < 0 && !opt->flags.zero)
		(write(fd, "-", 1) != -1) ? (*total)++ : (*total = -1);
	while(dif-- > 0)
		(write(fd, "0", 1) != -1) ? (*total)++ : (*total = -1);
}

void		ft_putnbr(int fd, t_opt *opt, int *total)
{
	char	buf[BUF];
	int		i;
	int		len;
	int64_t	num;

	num = opt->arg;
	ft_bzero(buf, BUF);
	itoa(buf, opt->arg, opt->precision);
	len = ft_strlen(buf);
	if (opt->flags.plus && num >= 0 && opt->flags.zero)
		(write(fd, "+", 1) != -1) ? (*total)++ : (*total = -1);
	if (num < 0 && opt->flags.zero)
		(write(fd, "-", 1) != -1) ? (*total)++ : (*total = -1);
	(opt->width &&!opt->flags.minus) ? padding(fd, opt, total, len) : 0;
	prepend(fd, opt, total, len);
	i = -1;
	while (buf[++i])
		(write(fd, &buf[i], 1) != -1) ? (*total)++ : (*total = -1);
	(opt->width && opt->flags.minus) ? padding(fd, opt, total, len) : 0;
}
