/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/12 11:46:43 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_printf.h"

int	main(void)
{
	long double		f = -0.0L;
	int			total;
	int			total_o;
	char		*format = "%.Le";

	total = ft_printf(format, f);
	write(1, "\n", 1);
	total_o = printf(format, f);
	printf("\ntotal: %d\ntotal_o: %d\n", total, total_o);
	ft_printf("%Lb", f);
	return (0);
}
