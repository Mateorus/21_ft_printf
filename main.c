/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/10 22:20:18 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char		c = 0;
	char		s[] = "12345678";
	long		i = 1;
	float		f = 1.0;
	long double	lf = 1.0;
	int			total;
	int			total_o;
	char		*format = "%b";

	total = ft_printf(format, i, 987654321987654321LL, 123456789123456789);
	write(1, "\n", 1);
	total_o = printf(format, i, i, i);
	printf("\ntotal: %d\ntotal_o: %d\n", total, total_o);
	return (0);
}
