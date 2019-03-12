/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:39:02 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/10 15:10:50 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	round(t_float *num, int precision)
{
	char	*tmp;

	tmp = num->frac;
	if (precision > (int)ft_strlen(tmp))
		return ;
	if (tmp[precision] >= '5')
	{
		!precision ? (tmp = ft_strchr(num->whole, 0)) : 0;
		tmp[--precision]++;
		while (tmp[precision] > '9')
		{
			tmp[precision] = '0';
			!precision ? (tmp = ft_strchr(num->whole, 0)) : 0;
			tmp[--precision]++;
		}
	}
}

static void	write_to_buf(char **buf, t_float *num, int  precision)
{
	int		len;
	char	*tmp;
	char	*buf_tmp;
	
	tmp = num->whole;
	while (*tmp == '0' && *(tmp + 1))
		tmp++;
	len = ft_strlen(tmp) + precision;
	assert((*buf = malloc(sizeof(**buf) * (len + 2))));
	buf_tmp = *buf;
	while (*tmp)
		*buf_tmp++ = *tmp++;
	tmp = num->frac;
	if (precision)
		*buf_tmp++ = '.';
	while (*tmp && precision--)
		*buf_tmp++ = *tmp++;
	while (precision-- > 0)
		*buf_tmp++ = '0';
	*buf_tmp = 0;
}

void		f_conversion(t_float *num, t_opt *opt, char **buf)
{
	int		precision;

	precision = opt->precision == -1 ? 6 : opt->precision;
	round(num, precision);
	write_to_buf(buf, num, precision);
}
