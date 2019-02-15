/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:11:12 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/15 00:56:38 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle(char *format, va_list ap, t_fp *fp, char **res)
{
	int		total;
	char	*sign_pos;
	t_opt	opt;

	total = 0;
	if (!(sign_pos = ft_strchr(format, '%')))
		return (-1);
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

int	ft_vfprintf(int fd, char *format, va_list ap)
{
	int			total;
	char		*res;
	t_fp		*fp;

	fp = (t_fp[]){skip, ft_putchar, ft_putstr, ft_putnbr,
		ft_putunbr, ft_putnbr_base16, ft_putnbr_base8, ft_putnbr_base2,
		ft_putfloat};
	res = 0;
	total = 0;
	if((total = handle(format, ap, fp, &res)) != -1)
		total = write(fd, res, total);
	else
		total = write(fd, format, ft_strlen(format));
	free(res);
	return (total);
}
