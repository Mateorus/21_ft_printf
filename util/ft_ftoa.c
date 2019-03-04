/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:02:50 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/04 20:06:55 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	special_value(long double n, char *s, int precision)
{
	int			exp;
	uint64_t	mantisa;

	exp = (*((uint64_t*)&n + 1) & 0x7fff);
	mantisa = *(uint64_t*)&n;
	if (exp == 0x7fff)
	{
		if (mantisa >> 62 == 3)
			ft_strncpy(s, "nan\0", 4);
		else
			ft_strncpy(s, "inf\0", 4);
		return (1);
	}
	if (!mantisa && !exp)
	{
		*s++ = '0';
		if (precision)
			*s++ = '.';
		while (precision--)
			*s++ = '0';
		*s = 0;
		return (1);
	}
	return (0);
}

static void	round(t_float *num, int len)
{
	char	*s;

	s = num->frac;
	if (len >= ft_strlen(s))
		return ;
	if (s[len] >= '5')
		s[--len]++;
	while (s[len] > '9')
	{
		s[len] = '0';
		if (len == 0)
			s = ft_strchr(num->whole, 0);
		s[--len]++;
	}
}

static void	double_dabble(long double n, t_float *num, int precision)
{
	int			exp;
	int			i;
	uint64_t	mantisa;

	exp = (*((uint64_t*)&n + 1) & 0x7fff);
	mantisa = *(uint64_t*)&n;
 	exp = !exp ? 1 - LD_BIAS : exp - LD_BIAS;
	get_whole_part(exp, &mantisa, &num->whole);
	get_frac_part(exp, &mantisa, &num->frac);
	if (!num->whole)
	{
		assert((num->whole = malloc(sizeof(*num->frac) * 2)));
		ft_strncpy(num->whole, "0\0", 2);
	}
	if (!num->frac)
	{
		assert((num->frac = malloc(sizeof(*num->frac) * (precision + 1))));
		i = 0;
		while (precision--)
			num->frac[i++] = '0';
		num->frac[i] = 0;
	}
}

static void	write_to_buf(t_float *num, char **buf, int precision)
{
	int			wh_len;
	int			fr_len;
	int			tl_len;
	char		*tmp;
	
	tmp = num->whole;
	while (*tmp == '0' && *(tmp + 1))
		tmp++;
	wh_len = ft_strlen(tmp);
	fr_len = ft_strlen(num->frac);
	tl_len = precision > fr_len ? precision + wh_len : fr_len + wh_len;
	*buf = malloc(sizeof(**buf) * (tl_len + 1 + 1));
	ft_strcpy(*buf, tmp);
	if (precision)
	{
		(*buf)[wh_len] = '.';
		if (precision > fr_len)
		{
			ft_strncpy((*buf) + wh_len + 1, num->frac, fr_len);
			precision -= fr_len;
			tmp = (*buf) + fr_len + wh_len + 1;
			while (precision--)
				*tmp++ = '0';
		}
		else
			ft_strncpy((*buf) + wh_len + 1, num->frac, precision);
		(*buf)[tl_len + 1] = 0;
	}
	else
		(*buf)[wh_len] = 0;
}

void		ft_ftoa(t_opt *opt, char **buf)
{
	int			precision;
	t_float		num;

	precision = opt->precision == -1 ? 6 : opt->precision;
	precision = opt->type == 'g' && !precision ? 1 : precision;
	if (special_value(opt->float_arg, *buf, precision)) 
		return ;
	num.whole = NULL;
	num.frac = NULL;
	double_dabble(opt->float_arg, &num, precision);
	round(&num, precision);
	write_to_buf(&num, buf, precision);
	free(num.whole);
	free(num.frac);
}
