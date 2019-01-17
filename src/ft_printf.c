/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:22 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/17 23:30:47 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	printf("%s", format);
	va_end(ap);
	return (0);
}
