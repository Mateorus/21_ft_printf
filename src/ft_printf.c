/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/12 12:33:39 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	char	*res;

	if (!format)
		return (-1);
	res = 0;
	va_start(ap, format);
	total = ft_vfprintf(&res, (char*)format, ap);
	write(1, res, total);
	free(res);
	va_end(ap);
	return (total);
}
