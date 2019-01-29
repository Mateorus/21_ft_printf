/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/26 16:16:05 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			total;

	if (!format)
		return (-1);
	va_start(ap, format);
	total = ft_vfprintf(1, (char*)format, ap);
	va_end(ap);
	return (total);
}
