/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:52 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/07 17:00:21 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa(char *buf, uintmax_t num, int precision)
{
	uintmax_t	tmp;
	int			i;

	!num ? buf[0] = '0' : 0;
	!num && !precision ? buf[0] = 0 : 0;
	i = 1;
	tmp = num;
	while (tmp /= 10)
		i++;
	buf[i] = 0;
	tmp = num;
	while (tmp)
	{
		buf[--i] = tmp % 10 + '0';
		tmp /= 10;
	}
}

static void	padding(t_opt *opt, char **res, int slen)
{
	int 		pad;
	char		c;
	char		*tmp;

	pad = opt->width - slen;
	tmp = *res;
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

	dif = opt->precision - nlen;
	while(dif-- > 0)
		*(*res)++ = '0';
}

int			ft_putunbr(char **res, int res_len, t_opt *opt)
{
	int			len;
	int			slen;
	int			nlen;
	char		*tmp;
	char		buf[BUF];

	itoa(buf, opt->arg, opt->precision);
	nlen = ft_strlen(buf);
	opt->precision != -1 ? opt->flags.zero = 0 : 0;
	opt->precision > nlen && nlen ? (slen = opt->precision) : (slen = nlen);
	opt->width > slen ? (len = opt->width) : (len = slen);
	len = ft_strncat(res, 0, res_len, len);
	tmp = (*res) + res_len;
	padding(opt, &tmp, slen);
	prepend(opt, &tmp, nlen);
	ft_strncpy(tmp, buf, nlen);
	return (len);
}
