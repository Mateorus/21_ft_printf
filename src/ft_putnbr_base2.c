/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/15 00:49:35 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, t_opt *opt)
{
	size_t	size;
	uint8_t	*pr;
	int		i;
	char	*copy;

	copy = buf;
	opt->arg ? (size = sizeof(opt->arg)) : (size = sizeof(opt->float_arg));
	opt->arg ? (pr = (uint8_t*)&opt->arg) : (pr = (uint8_t*)&opt->float_arg);
	buf[size * 8] = 0;
	i = 1;
	while (size--)
	{
		buf[0] = (((*pr) >> 7) & 0x1) + '0';
		buf[1] = (((*pr) >> 6) & 0x1) + '0';
		buf[2] = (((*pr) >> 5) & 0x1) + '0';
		buf[3] = (((*pr) >> 4) & 0x1) + '0';
		buf[4] = (((*pr) >> 3) & 0x1) + '0';
		buf[5] = (((*pr) >> 2) & 0x1) + '0';
		buf[6] = (((*pr) >> 1) & 0x1) + '0';
		buf[7] = ((*pr++) & 0x1) + '0';
		(int)(((char*)&i)[0]) ? ft_revstr(buf, 8) : 0;
		buf += 8;
	}
	(int)(((char*)&i)[0]) ? ft_revstr(copy, ft_strlen(copy)) : 0;
}

static void sufix(t_opt *opt, char **res)
{
	char		*pr;

	(void)opt;
	pr = (char[2]){'0', 'b'};
	ft_strncpy(*res, pr, 2);
	(*res) += 2;
}

static void	padding(t_opt *opt, char **res, int slen)
{
	int 		pad;
	char		c;
	char		*tmp;

	pad = opt->width - slen;
	tmp = *res;
	if (opt->flags.hash && opt->flags.zero)
		sufix(opt, res);
	if (pad < 1)
		return ;
	opt->flags.minus ? tmp = tmp + slen : (tmp = (*res));
	opt->flags.zero && opt->precision == -1 ? (c = '0') : (c = ' ');
	opt->flags.minus ? 0 : (*res += pad);
	while (pad-- > 0)
		*tmp++ = c;
}

static void	prepend(t_opt *opt, char **res, int nlen)
{
	int		dif;

	dif = opt->precision - nlen;
	if (opt->flags.hash && !opt->flags.zero)
		sufix(opt, res);
	while(dif-- > 0)
		*(*res)++ = '0';
}

int			ft_putnbr_base2(char **res, int res_len, t_opt *opt)
{
	int			len;
	int			slen;
	int			nlen;
	char		*tmp;
	char		buf[BUF];

	itoa(buf, opt);
	if (opt->flags.hash)
		nlen = ft_strlen(ft_strchr(buf, '1'));
	else
		nlen = ft_strlen(buf);
	opt->precision != -1 ? (opt->flags.zero = 0) : 0;
	opt->precision > nlen && nlen ? (slen = opt->precision) : (slen = nlen);
	opt->flags.hash ? (slen += 2) : 0;
	opt->width > slen ? (len = opt->width) : (len = slen);
	len = ft_strncat(res, 0, res_len, len);
	tmp = (*res) + res_len;
	padding(opt, &tmp, slen);
	prepend(opt, &tmp, nlen);
	opt->flags.hash ? ft_strncpy(tmp, ft_strchr(buf, '1'), nlen) :
		ft_strncpy(tmp, buf, nlen);
	return (len);
}
