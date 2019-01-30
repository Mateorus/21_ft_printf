/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:27:15 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/29 22:27:09 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char		c = 'C';
	char		*s = "this";
	int			i = 10;
	float		f = 0.0;
	int			total;
	int			total_o;
	char		*format = "%o\n";

	total = ft_printf(format, i);
	total_o = printf(format, i);
	printf("total: %d\ntotal_o: %d\n", total, total_o);
	return (0);
}
