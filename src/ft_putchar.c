/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:05:38 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/07 20:37:58 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	padding(t_opt *opt, char **res)
{
	int		pad;
	char	c;
	char	*tmp;

	pad = opt->width - 1;
	tmp = *res;
	if (pad < 1)
		return ;
	opt->flags.minus ? tmp = tmp + 1 : (tmp = (*res));
	opt->flags.zero ? (c = '0') : (c = ' ');
	opt->flags.minus ? 0 : (*res += pad);
	while (pad-- > 0)
		*tmp++ = c;
}

int			ft_putchar(char **res, int res_len, t_opt *opt)
{
	int		len;
	int		width;
	char	*tmp;

	width = opt->width;
	width > 1 ? (len = width) : (len = 1);
	len = ft_strncat(res, 0, res_len, len);
	tmp = (*res) + res_len;
	padding(opt, &tmp);
	if (opt->type == '%')
		*tmp++ = '%';
	else
		*tmp++ = opt->arg;
	return (len);
}
