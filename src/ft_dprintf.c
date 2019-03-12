/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:15:34 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/12 13:47:28 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		total;
	char	*res;

	if (!format)
		return (-1);
	res = 0;
	va_start(ap, format);
	total = ft_vfprintf(&res, (char*)format, ap);
	write(fd, res, total);
	free(res);
	va_end(ap);
	return (total);
}
