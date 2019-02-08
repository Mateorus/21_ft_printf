/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:04:08 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/07 15:31:16 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	padding(t_opt *opt,char **res, int slen)
{
	int		pad;
	char	c;
	char	*tmp;

	 pad = opt->width - slen;
	 tmp = *res;
	 if (pad < 1)
		return ;
	 opt->flags.minus ? tmp = tmp + slen : (tmp = (*res));
	 opt->flags.zero ? (c = '0') : (c = ' ');
	 opt->flags.minus ? 0 : (*res += pad);
	 while (pad-- > 0)
		 *tmp++ = c;
}

int			ft_putstr(char **res, int res_len, t_opt *opt)
{
	char	*s;
	char	*tmp;
	int		len;
	int		slen;

	s = "(null)";
	if (!opt->arg)
		opt->arg = (uintmax_t)s;
	s = (char*)opt->arg;
	slen = ft_strlen(s);
	(opt->precision >= 0 && opt->precision < slen) ? (slen = opt->precision) : 0;
	opt->width > slen ? (len = opt->width) : (len = slen);
	len = ft_strncat(res, 0, res_len, len);
	tmp = (*res) + res_len;
	padding(opt, &tmp, slen);
	ft_strncpy(tmp, s, slen);
	return (len);
}
