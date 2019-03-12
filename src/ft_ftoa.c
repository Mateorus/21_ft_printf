/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:02:50 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/10 14:03:03 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	special_value(t_opt *opt, char **s)
{
	int			exp;
	uint64_t	mantisa;
	long double n;

	n = opt->float_arg;
	exp = (*((uint64_t*)&n + 1) & 0x7fff);
	mantisa = *(uint64_t*)&n;
	if (exp == 0x7fff)
	{
		opt->flags.zero = 0;
		assert((*s = malloc(sizeof(**s) * 4)));
		if (mantisa >> 62 == 3)
		{
			*((uint64_t*)&opt->float_arg + 1) = exp;
			opt->flags.space = 0;
			opt->flags.plus = 0;
			ft_strncpy(*s, "nan\0", 4);
		}
		else
			ft_strncpy(*s, "inf\0", 4);
		return (1);
	}
	return (0);
}

static void	double_dabble(long double n, t_float *num)
{
	int			exp;
	uint64_t	mantisa;

	exp = (*((uint64_t*)&n + 1) & 0x7fff);
	mantisa = *(uint64_t*)&n;
	exp = mantisa ? exp : 0;
	if (mantisa)
 		exp = !exp ? 1 - LD_BIAS : exp - LD_BIAS;
	get_whole_part(&exp, &mantisa, &num->whole);
	get_frac_part(exp, &mantisa, &num->frac);
	if (!num->whole)
	{
		assert((num->whole = malloc(sizeof(*num->frac) * 2)));
		ft_strncpy(num->whole, "0\0", 2);
	}
	if (!num->frac)
	{
		assert((num->frac = malloc(sizeof(*num->frac))));
		*num->frac = 0;
	}
}

void		ft_ftoa(t_opt *opt, char **buf)
{
	t_float		num;

	if (special_value(opt, buf)) 
		return ;
	ft_bzero(&num, sizeof(num));
	double_dabble(opt->float_arg, &num);
	if (opt->type == 'e')
		e_conversion(&num, opt, buf);
	else
		f_conversion(&num, opt, buf);
	free(num.whole);
	free(num.frac);
}
