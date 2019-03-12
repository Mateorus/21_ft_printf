/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:56:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/12 11:45:31 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		exptoa(char *buf, int num)
{
	long long	tmp;
	int			i;

	*buf++ = 'e';
	*buf++ = num < 0 ? '-' : '+';
	num > -10 && num < 10 ? *buf++ = '0' : 0;
	i = 1;
	tmp = num;
	if (tmp < 0)
		tmp *= -1;
	while (num /= 10)
		i++;
	buf[i] = 0;
	while (i)
	{
		buf[--i] = tmp % 10 + '0';
		tmp /= 10;
	}
}

int			get_exp(t_float *num)
{
	char	*tmp;
	int		exp;

	tmp = num->whole;
	while (*tmp == '0')
		tmp++;
	exp = -1;
	while (*tmp++)
		exp++;
	if (exp == -1)
	{
		if (!*tmp)
			return (0);
		tmp = num->frac;
		while (*tmp++ == '0')
			exp--;
	}
	return (exp);
}

static void	round(t_float *num, int precision, int *exp)
{
	char	*tmp;
	char	*check_0;

	if ( precision > ((int)ft_strlen(num->frac) + *exp))
		return ;
	check_0 = num->whole;
	while (*check_0 == '0')
		check_0++;
	precision = precision - *exp;
	tmp = precision < 0 ? ft_strchr(num->whole, 0) : num->frac;
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
	if (*--check_0 != '0')
		(*exp)++;
}

static void	write_to_buf(char **buf, t_float *num, int precision, int exp)
{
	char		*tmp;
	char		*tmp2;
	char		*buf_tmp;
	
	assert((*buf = malloc(sizeof(**buf) * (precision + 9))));
	buf_tmp = *buf;
	tmp = exp < 0 ? 0 : ft_strchr(num->whole, 0) - exp - 1;
	tmp2 = exp < 0 ? num->frac + -exp - 1 : num->frac;
	*buf_tmp++ = *tmp ? *tmp++ : *tmp2++;
	precision ? *buf_tmp++ = '.' : 0;
	while (*tmp && precision-- > 0)
		*buf_tmp++ = *tmp++;
	while (*tmp2 && precision-- > 0)
		*buf_tmp++ = *tmp2++;
	while (precision-- > 0)
		*buf_tmp++ = '0';
	tmp = num->exp;
	while (*tmp)
		*buf_tmp++ = *tmp++;
	*buf_tmp = 0;
}

void		e_conversion(t_float *num, t_opt *opt, char **buf)
{
	int		exp;
	int		precision;

	precision = opt->precision == -1 ? 6 : opt->precision;
	exp = get_exp(num);
	round(num, precision, &exp);
	exptoa(num->exp, exp);
	write_to_buf(buf, num, precision, exp);
}
