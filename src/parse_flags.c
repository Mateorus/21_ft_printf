/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:17:35 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/21 23:44:21 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(const char *format, t_opt *opt)
{
	ft_bzero(opt, sizeof(*opt));
	if (*format == 'c')
		opt->type = c;
	return (2);
}
