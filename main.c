/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/15 00:54:10 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char		c = 0;
	char		s[] = "123456789";
	long		i = 1;
	float		f = 1;
	long double	lf = 1.23456789123456789;
	int			total;
	int			total_o;
	char		*format = "%lb";

	total = ft_printf(format, 1.234567);
	write(1, "\n", 1);
	total_o = printf(format, 0.45, 0.45, 0.45);
	printf("\ntotal: %d\ntotal_o: %d\n", total, total_o);
	ft_revstr(s, ft_strlen(s));
	printf("%s", s);
	return (0);
}
