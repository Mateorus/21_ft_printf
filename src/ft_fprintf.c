/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:15:34 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/06 17:40:04 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			total;

	if (!format)
		return (-1);
	va_start(ap, format);
	total = ft_vfprintf(fd, (char*)format, ap);
	va_end(ap);
	return (total);
}
