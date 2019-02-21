/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/21 15:29:31 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char		c = 0;
	char		s[] = "123456789";
	long		i = -3;
	long double		f = 1.8e+400L;
	long double	lf = 1.123456;
	int			total;
	int			total_o;
	char		*format = "%.25Lf";

	total = ft_printf(format, f);
	write(1, "\n", 1);
	total_o = printf(format, f);
	printf("\ntotal: %d\ntotal_o: %d\n", total, total_o);
	ft_printf("%Lb", f);
	return (0);
}
