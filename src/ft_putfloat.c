/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:40:09 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/21 14:43:22 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			ft_putfloat(char **res, int res_len, t_opt *opt)
{
	int		len;
	int		nlen;
	int		slen;
	char	*tmp;
	char	*buf;

	ft_ftoa(opt, &buf);
	/* *buf == '0' ? buf++ : 0; */
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
	free(buf);
	return (len);
}
