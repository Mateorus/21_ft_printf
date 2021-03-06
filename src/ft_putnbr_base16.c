/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base16.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/07 18:00:38 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, t_opt *opt)
{
	int			i;
	char		x;
	uintmax_t	tmp;
	uintmax_t	num;

	opt->type == 'X' ? (x = 'A') : (x = 'a');
	num = opt->arg;
	!num ? buf[0] = '0' : 0;
	!num && !opt->precision ? buf[0] = 0 : 0;
	i = 1;
	tmp = num;
	while (tmp >>= 4)
		i++;
	buf[i] = 0;
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

static void sufix(t_opt *opt, char **res)
{
	char		*pr;

	opt->type == 'X' ? (pr = (char[2]){'0', 'X'}) : (pr = (char[2]){'0', 'x'});
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
	if (opt->flags.hash && opt->flags.zero && (opt->arg || opt->type == 'p'))
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
	if (opt->flags.hash && !opt->flags.zero && (opt->arg || opt->type == 'p'))
		sufix(opt, res);
	while(dif-- > 0)
		*(*res)++ = '0';
}

int			ft_putnbr_base16(char **res, int res_len, t_opt *opt)
{
	int			len;
	int			slen;
	int			nlen;
	char		*tmp;
	char		buf[BUF];

	itoa(buf, opt);
	nlen = ft_strlen(buf);
	opt->precision != -1 ? (opt->flags.zero = 0) : 0;
	opt->precision > nlen && nlen ? (slen = opt->precision) : (slen = nlen);
	(opt->flags.hash && opt->arg) || opt->type == 'p' ? (slen += 2) : 0;
	opt->width > slen ? (len = opt->width) : (len = slen);
	len = ft_strncat(res, 0, res_len, len);
	tmp = (*res) + res_len;
	padding(opt, &tmp, slen);
	prepend(opt, &tmp, nlen);
	ft_strncpy(tmp, buf, nlen);
	return (len);
}
