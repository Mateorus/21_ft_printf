/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:05:38 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 23:32:22 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int fd, t_opt *opt, int *total)
{
	if (opt->width && !opt->flags.minus)
	{
		while (--opt->width)
			(write(fd, " ", 1) != -1) ? (*total)++ : (*total = -1);
	}
	if (opt->type == '%')
		(write(fd, "%", 1) != -1) ? (*total)++ : (*total = -1);
	else
		(write(fd, &(opt->arg), 1) != -1) ? (*total)++ : (*total = -1);
	if (opt->width && opt->flags.minus)
	{
		while (--opt->width)
			(write(fd, " ", 1) != -1) ? (*total)++ : (*total = -1);
	}
}
