/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:56:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/09 23:19:55 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	e_conversion(t_float *num, t_opt *opt, char **buf)
{
	return ;
}
/* void	exptoa(char *buf, int num) */
/* { */
/* 	long long	tmp; */
/* 	int			i; */

/* 	*buf++ = 'e'; */
/* 	tmp = num; */
/* 	*buf++ = tmp < 0 ? '-' : '+'; */
/* 	if (tmp < 0) */
/* 		tmp *= -1; */
/* 	i = 2; */
/* 	while (tmp /= 10) */
/* 		i++; */
/* 	buf[i] = 0; */
/* 	tmp = num; */
/* 	while (i) */
/* 	{ */
/* 		buf[--i] = tmp % 10 + '0'; */
/* 		tmp /= 10; */
/* 	} */
/* } */

/* int		get_exp(t_float *num) */
/* { */
/* 	char	*tmp; */
/* 	int		exp; */

/* 	tmp = num->whole; */
/* 	while (*tmp == '0') */
/* 		tmp++; */
/* 	exp = -1; */
/* 	while (*tmp++) */
/* 		exp++; */
/* 	if (exp == -1) */
/* 	{ */
/* 		tmp = num->frac; */
/* 		while (*tmp++ == '0') */
/* 			exp--; */
/* 	} */
/* 	return (exp); */
/* } */

/* static void	round(t_float *num, int precision) */
/* { */
/* 	char	*tmp; */

/* 	tmp = precision >= 0 ? num->frac : ft_strchr(num->whole, 0); */
/* 	precision < 0 ? *num->frac = 0 : 0; */
/* 	if (tmp[precision] >= '5') */
/* 	{ */
/* 		tmp[precision] = 0; */
/* 		!precision ? (tmp = ft_strchr(num->whole, 0)) : 0; */
/* 		tmp[--precision]++; */
/* 		while (tmp[precision] > '9') */
/* 		{ */
/* 			tmp[precision] = '0'; */
/* 			!precision ? (tmp = ft_strchr(num->whole, 0)) : 0; */
/* 			tmp[--precision]++; */
/* 		} */
/* 	} */
/* 	else */
/* 		tmp[precision] = 0; */
/* } */

/* static void	write_to_buf(char **buf, t_float *num, int exp) */
/* { */
/* 	int			len; */
/* 	char		*tmp; */
/* 	char		*buf_tmp; */
	
/* 	tmp = num->whole; */
/* 	while (*tmp == '0' && *(tmp + 1)) */
/* 		tmp++; */
/* 	len = ft_strlen(tmp) + ft_strlen(num->frac) + ft_strlen(num->exp); */
/* 	assert((*buf = malloc(sizeof(**buf) * (len + 2)))); */
/* 	buf_tmp = *buf; */
/* 	while (*tmp) */
/* 	{ */
/* 		if (exp-- == 0) */
/* 			*buf_tmp++ = '.'; */
/* 		*buf_tmp++ = *tmp++; */
/* 	} */
/* 	tmp = num->frac; */
/* 	while (*tmp) */
/* 		*buf_tmp++ = *tmp++; */
/* 	tmp = num->exp; */
/* 	while (*tmp) */
/* 		*buf_tmp++ = *tmp++; */
/* 	*tmp = 0; */
/* } */
