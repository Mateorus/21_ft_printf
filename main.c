/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/08 23:47:43 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char		c = 0;
	char		*s = "abc";
	int			i = 8;
	float		f = 0.0;
	int			total;
	int			total_o;
	char		*format = "%m %i";

	total = ft_printf(format, i, 5);
	write(1, "\n", 1);
	total_o = printf(format, i, 5);
	printf("\ntotal: %d\ntotal_o: %d\n", total, total_o);
	return (0);
}
