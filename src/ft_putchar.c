/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:05:38 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/21 23:34:08 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(t_opt *opt, va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}
