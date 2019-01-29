/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:52 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 17:47:45 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, uint64_t num, int precision)
{
	uint64_t	tmp;
	int			i;

	!num ? buf[0] = '0' : 0;
	!num && !precision ? buf[0] = 0 : 0;
	i = 1;
	tmp = num;
	while (tmp /= 10)
		i++;
	tmp = num;
	while (tmp)
	{
		buf[--i] = tmp % 10 + '0';
		tmp /= 10;
	}
}

static void	padding(int fd, t_opt *opt, int *total, int len)
{
	int 		width;
	uint64_t	num;
	char		c[1];

	c[0] = ' ';
	num = opt->arg;
	width = opt->width;
	(opt->precision > len) ? (width -= opt->precision) : (width -= len);
	if (opt->flags.zero && opt->precision < 0)
		c[0] = '0';
	while (width-- > 0)
		(write(fd, c, 1) != -1) ? (*total)++ : (*total = -1);
}

static void	prepend(int fd, t_opt *opt, int *total, int len)
{
	int			dif;

	dif = opt->precision - len;
	while(dif-- > 0)
		(write(fd, "0", 1) != -1) ? (*total)++ : (*total = -1);
}

void		ft_putunbr(int fd, t_opt *opt, int *total)
{
	char		buf[BUF];
	int			i;
	int			len;
	uint64_t	num;

	num = opt->arg;
	ft_bzero(buf, BUF);
	itoa(buf, opt->arg, opt->precision);
	len = ft_strlen(buf);
	(opt->width &&!opt->flags.minus) ? padding(fd, opt, total, len) : 0;
	prepend(fd, opt, total, len);
	i = -1;
	while (buf[++i])
		(write(fd, &buf[i], 1) != -1) ? (*total)++ : (*total = -1);
	(opt->width && opt->flags.minus) ? padding(fd, opt, total, len) : 0;
}
