/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:57:09 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/12 14:01:52 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sprintf(char **s, const char *format, ...)
{
	va_list	ap;
	int		total;
	char	*res;

	if (!format)
		return (-1);
	res = 0;
	va_start(ap, format);
	total = ft_vfprintf(&res, (char*)format, ap);
	*s = res;
	va_end(ap);
	return (total);
}
