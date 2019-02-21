/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:02:50 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/21 15:33:24 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//DELETE!!!!
#include <math.h>
#include <string.h>
#include "ft_printf.h"

int		special_value(long double n, char *s)
{
	uint64_t	frac;
	uint16_t	exp;
	uint64_t	*value;

	value = (uint64_t*)&n;
	frac = *value;
	exp = *(value + 1) | 0x8000;
	if (exp == 0xffff)
	{
		if (frac == 0xffffffffffffffff)
			ft_strncpy(s, "nan\0", 4);
		else
			ft_strncpy(s, "inf\0", 4);
		return (1);
	}
	if (n == 0.0)
	{
		ft_strncpy(s, "0\0", 2);
		return (1);
	}
	return (0);
}

void	ft_round(char *s)
{
	int	len;

	len = ft_strchr(s, '.') - s;
	len += 19;
	if (s[len] >= '5')
	{
		if (s[--len] == '.')
			len--;
		s[len]++;
		while (len > 0)
		{
			if (s[len] == '.')
				len--;
			if (s[len] > '9')
			{
				s[len] = '0';
				s[len - 1]++;
			}
			len--;
		}
	}
}

void	float_engine(long double n, int precision, int m, char *s)
{
	int			digit;
	long double weight;
	long double tmp;

	if (n < 0.0)
		n = -n;
	*s++ = '0';
	while (precision) 
	{
		weight = pow(10.0, m);
		m == -1 ? weight -= 0.000000000000000005551L : 0;
		digit = floor(n / weight);
		tmp = (digit * weight);
		n -= tmp;
		*s++ = '0' + digit;
		if (m-- == 0)
			*s++ = '.';
		m < -1 ? precision-- : 0;
	}
	*s = 0;
}

void	ft_ftoa(t_opt *opt, char **buf)
{
	int			precision;
	int			mag;
	long double	n;

	n = opt->float_arg;
	mag = log10l(n);
	mag < 0 ? mag = 0 : 0;
	precision = opt->precision == -1 ? 19 : opt->precision + 1;
	*buf = malloc(sizeof(**buf) * (mag + 1 + precision + 2));
	if (special_value(n, *buf))
		return ;
	float_engine(n, precision, mag, *buf);
	ft_round(*buf);
}
        /* int useExp = (m >= 14 || (neg && m >= 9) || m <= -9); */
        // set up for scientific notation
        /* if (useExp) { */
        /*     if (m < 0) */
        /*        m -= 1.0; */
        /*     n = n / pow(10.0, m); */
        /*     m1 = m; */
        /*     m = 0; */
        /* } */
		/* while (n > 0 && PRECISION) */
		/* { */
		/* 	n = n / pow(10, m); */
		/* 	digit = (int)n; */
		/* 	n = (n - digit) * pow(10, m--); */
            /* *(c++) = '0' + digit; */
            /* if (m == -1) */
                /* *(c++) = '.'; */
		/* 	PRECISION--; */
		/* } */
        /* if (useExp) { */
        /*     // convert the exponent */
        /*     int i, j; */
        /*     *(c++) = 'e'; */
        /*     if (m1 > 0) { */
        /*         *(c++) = '+'; */
        /*     } else { */
        /*         *(c++) = '-'; */
        /*         m1 = -m1; */
        /*     } */
        /*     m = 0; */
        /*     while (m1 > 0) { */
        /*         *(c++) = '0' + m1 % 10; */
        /*         m1 /= 10; */
        /*         m++; */
        /*     } */
        /*     c -= m; */
        /*     for (i = 0, j = m-1; i<j; i++, j--) { */
        /*         // swap without temporary */
        /*         c[i] ^= c[j]; */
        /*         c[j] ^= c[i]; */
        /*         c[i] ^= c[j]; */
        /*     } */
        /*     c += m; */
        /* } */
