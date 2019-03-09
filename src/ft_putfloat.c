/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:40:09 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/05 10:37:42 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	padding(t_opt *opt, char **res, int slen)
{
	int 	pad;
	int		sign;
	char	c;
	char	*tmp;

	sign = (*((uint64_t*)&opt->float_arg + 1) & 0x8000);
	pad = opt->width - slen;
	tmp = *res;
	if (opt->flags.space && !sign)
		*(*res)++ = ' ';
	if (opt->flags.plus && !sign && opt->flags.zero)
		*(*res)++ = '+';
	if (sign && opt->flags.zero)
		*(*res)++ = '-';
	if (pad < 1)
		return ;
	opt->flags.minus ? tmp = tmp + slen : (tmp = (*res));
	opt->flags.zero ? (c = '0') : (c = ' ');
	opt->flags.minus ? 0 : (*res += pad);
	while (pad-- > 0)
		*tmp++ = c;
}

static void	prepend(t_opt *opt, char **res)
{
	int		sign;

	sign = (*((uint64_t*)&opt->float_arg + 1) & 0x8000);
	if (!sign && !opt->flags.zero && opt->flags.plus)
		*(*res)++ = '+';
	if (sign && !opt->flags.zero)
		*(*res)++ = '-';
}

int			ft_putfloat(char **res, int res_len, t_opt *opt)
{
	int		len;
	int		nlen;
	int		slen;
	char	*tmp;
	char	*buf;

	ft_ftoa(opt, &buf);
	nlen = ft_strlen(buf);
	slen = opt->flags.space || opt->flags.plus ||
	 (int)(*((uint64_t*)&opt->float_arg + 1) & 0x8000) ? nlen + 1 : nlen;
	opt->width > slen ? (len = opt->width) : (len = slen);
	len = ft_strncat(res, 0, res_len, len);
	tmp = (*res) + res_len;
	padding(opt, &tmp, slen);
	prepend(opt, &tmp);
	ft_strncpy(tmp, buf, nlen);
	free(buf);
	return (len);
}
