/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base16.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 22:07:09 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, t_opt *opt)
{
	uint64_t	tmp;
	uint64_t	num;
	char		x;
	int			i;

	opt->type == 'x' ? (x = 'a') : (x = 'A');
	num = opt->arg;
	!num ? buf[0] = '0' : 0;
	!num && !opt->precision ? buf[0] = 0 : 0;
	i = 1;
	tmp = num;
	while (tmp >>= 4)
		i++;
	while (num)
	{
		tmp  = 0xF & num;
		if (tmp > 9)
			tmp = tmp - 10 + x;
		else
			tmp = tmp + '0';
		buf[--i] = tmp;
		num >>= 4;
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
		width -= 2;
	if (opt->flags.zero && opt->precision < 0 && !opt->flags.minus)
		c[0] = '0';
	while (width-- > 0)
		(write(fd, c, 1) != -1) ? (*total)++ : (*total = -1);
}

static void	prepend(int fd, t_opt *opt, int *total, int len)
{
	int		dif;
	char	*pr;

	dif = opt->precision - len;
	opt->type == 'x' ? (pr = (char[2]){'0', 'x'}) : (pr = (char[2]){'0', 'X'});
	if (opt->flags.hash && !opt->flags.zero && opt->arg)
		(write(fd, pr, 2) != -1) ? (*total) += 2 : (*total = -1);
	while(dif-- > 0)
		(write(fd, "0", 1) != -1) ? (*total)++ : (*total = -1);
}

void	ft_putnbr_base16(int fd, t_opt *opt, int *total)
{
	char		buf[BUF];
	int			i;
	int			len;
	char		*pr;

	opt->type == 'x' ? (pr = (char[2]){'0', 'x'}) : (pr = (char[2]){'0', 'X'});
	ft_bzero(buf, BUF);
	itoa(buf, opt);
	len = ft_strlen(buf);
	if (opt->flags.hash && opt->flags.zero && opt->arg)
		(write(fd, pr, 2) != -1) ? (*total) += 2 : (*total = -1);
	(opt->width &&!opt->flags.minus) ? padding(fd, opt, total, len) : 0;
	prepend(fd, opt, total, len);
	i = -1;
	while (buf[++i])
		(write(fd, &buf[i], 1) != -1) ? (*total)++ : (*total = -1);
	(opt->width && opt->flags.minus) ? padding(fd, opt, total, len) : 0;
}
