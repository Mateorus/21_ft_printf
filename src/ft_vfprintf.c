/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:11:12 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/12 13:50:51 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(char **res, char *format, va_list ap)
{
	int		total;
	char	*sign_pos;
	t_opt	opt;
	t_fp	*fp;

	fp = (t_fp[]){skip, ft_putchar, ft_putstr, ft_putnbr,
		ft_putunbr, ft_putnbr_base16, ft_putnbr_base8, ft_putnbr_base2,
		ft_putfloat};
	total = 0;
	sign_pos = ft_strchr(format, '%');
	while (sign_pos)
	{
		total = ft_strncat(res, format, total, sign_pos - format);
		format = sign_pos;
		total = fp[parser(&format, &opt, ap)](res, total, &opt);
		sign_pos = ft_strchr(format, '%');
	}
	total = ft_strncat(res, format, total, ft_strlen(format));
	return (total);
}
