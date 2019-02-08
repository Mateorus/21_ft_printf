/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:32:46 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/07 15:44:53 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, intmax_t num, int precision)
{
	intmax_t	tmp;
	int			i;

	!num ? buf[0] = '0' : 0;
	!num && !precision ? buf[0] = 0 : 0;
	i = 1;
	tmp = num;
	while (tmp /= 10)
		i++;
	buf[i] = 0;
	tmp = num;
	if ((uintmax_t)tmp == -9223372036854775808U)
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

static void	padding(t_opt *opt, char **res, int slen)
{
	int 		pad;
	intmax_t	num;
	char		c;
	char		*tmp;

	num = opt->arg;
	pad = opt->width - slen;
	tmp = *res;
	if (opt->flags.space && num >= 0)
		*(*res)++ = ' ';
	if (opt->flags.plus && opt->arg >= 0 && opt->flags.zero)
		*(*res)++ = '+';
	if (opt->arg < 0 && opt->flags.zero)
		*(*res)++ = '-';
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
	int			dif;
	intmax_t	num;

	num = opt->arg;
	dif = opt->precision - nlen;
	if (num >= 0 && !opt->flags.zero && opt->flags.plus)
		*(*res)++ = '+';
	if (num < 0 && !opt->flags.zero)
		*(*res)++ = '-';
	while(dif-- > 0)
		*(*res)++ = '0';
}

int			ft_putnbr(char **res, int res_len, t_opt *opt)
{
	int		len;
	int		nlen;
	int		slen;
	char	*tmp;
	char	buf[BUF];

	itoa(buf, opt->arg, opt->precision);
	nlen = ft_strlen(buf);
	opt->precision != -1 ? opt->flags.zero = 0 : 0;
	(opt->precision > nlen && nlen) ? (slen = opt->precision) : (slen = nlen);
	(opt->flags.space || opt->flags.plus || opt->arg < 0) ? slen++ : 0;
	opt->width > slen ? (len = opt->width) : (len = slen);
	len = ft_strncat(res, 0, res_len, len);
	tmp = (*res) + res_len;
	padding(opt, &tmp, slen);
	prepend(opt, &tmp, nlen);
	ft_strncpy(tmp, buf, nlen);
	return (len);
}
