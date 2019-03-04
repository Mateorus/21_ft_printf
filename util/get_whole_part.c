/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_whole_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:30:43 by gstiedem          #+#    #+#             */
/*   Updated: 2019/03/04 16:09:48 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	shift(uint64_t *limb, int size)
{
	uint64_t	tmp;
	uint64_t	tmp2;

	tmp = 0;
	while(size--)
	{
		tmp2 = *limb & 0x8000000000000000;
		tmp2 >>= 63;
		*limb <<= 1;
		*limb |= tmp;
		tmp = tmp2;
		limb++;
	}
}

static void	increment(uint64_t *start, size_t size)
{
	uint64_t	tmp;

	while (size--)
	{
		tmp = *start;
		(tmp & 0xf) > 4 ? tmp += 3 : 0;
		((tmp >> 4) & 0xf) > 4 ? tmp += 0x30 : 0;
		((tmp >> 8) & 0xf) > 4 ? tmp += 0x300 : 0;
		((tmp >> 12) & 0xf) > 4 ? tmp += 0x3000 : 0;
		((tmp >> 16) & 0xf) > 4 ? tmp += 0x30000 : 0;
		((tmp >> 20) & 0xf) > 4 ? tmp += 0x300000 : 0;
		((tmp >> 24) & 0xf) > 4 ? tmp += 0x3000000 : 0;
		((tmp >> 28) & 0xf) > 4 ? tmp += 0x30000000 : 0;
		((tmp >> 32) & 0xf) > 4 ? tmp += 0x300000000 : 0;
		((tmp >> 36) & 0xf) > 4 ? tmp += 0x3000000000 : 0;
		((tmp >> 40) & 0xf) > 4 ? tmp += 0x30000000000 : 0;
		((tmp >> 44) & 0xf) > 4 ? tmp += 0x300000000000 : 0;
		((tmp >> 48) & 0xf) > 4 ? tmp += 0x3000000000000 : 0;
		((tmp >> 52) & 0xf) > 4 ? tmp += 0x30000000000000 : 0;
		((tmp >> 56) & 0xf) > 4 ? tmp += 0x300000000000000 : 0;
		((tmp >> 60) & 0xf) > 4 ? tmp += 0x3000000000000000 : 0;
		*start = tmp;
		start++;
	}
}

static void	write_to_buf(uint64_t *end, size_t size, char *buf)
{
	uint64_t	tmp;

	while (size--)
	{
		tmp = *end;
		*buf++ = ((tmp >> 60) & 0xf) + '0';
		*buf++ = ((tmp >> 56) & 0xf) + '0';
		*buf++ = ((tmp >> 52) & 0xf) + '0';
		*buf++ = ((tmp >> 48) & 0xf) + '0';
		*buf++ = ((tmp >> 44) & 0xf) + '0';
		*buf++ = ((tmp >> 40) & 0xf) + '0';
		*buf++ = ((tmp >> 36) & 0xf) + '0';
		*buf++ = ((tmp >> 32) & 0xf) + '0';
		*buf++ = ((tmp >> 28) & 0xf) + '0';
		*buf++ = ((tmp >> 24) & 0xf) + '0';
		*buf++ = ((tmp >> 20) & 0xf) + '0';
		*buf++ = ((tmp >> 16) & 0xf) + '0';
		*buf++ = ((tmp >> 12) & 0xf) + '0';
		*buf++ = ((tmp >> 8) & 0xf) + '0';
		*buf++ = ((tmp >> 4) & 0xf) + '0';
		*buf++ = (tmp & 0xf) + '0';
		end--;
	}
	*buf = 0;
}

static void	extract_whole_part(int exp, uint64_t *mantisa, uint64_t *limb)
{
	int			pos;
	uint64_t	tmp;

	while (exp >= 0 && *mantisa)
	{
		pos = exp / 64;
		tmp = *mantisa & 0x8000000000000000 ? 1ULL << (exp % 64) : 0;
		*mantisa <<= 1;
		limb[pos] += tmp;
		exp--;
	}
}

void	get_whole_part(int exp, uint64_t *mantisa, char **buf)
{
	size_t		reg_size;
	size_t		total_size;
	uint64_t	*bcd_start;
	uint64_t	steps;
	uint64_t	*limb;

	if (exp < 0)
		return ;
	reg_size = exp / 64 + 1;
	steps = reg_size << 6;
	total_size = reg_size + (4 * (steps / 3.0 + 1) / 64) + 1;
	assert((limb = malloc(sizeof(*limb) * total_size)));
	ft_bzero(limb, total_size * 8);
	extract_whole_part(exp, mantisa, limb);
	bcd_start = limb + reg_size;
	while (steps--)
	{
		increment(bcd_start, total_size - reg_size);
		shift(limb, total_size);
	}
	assert((*buf = malloc(sizeof(**buf) * ((total_size - reg_size) * 16 + 2))));
	**buf = '0';
	write_to_buf(limb + total_size - 1, total_size - reg_size, (*buf) + 1);
	free(limb);
}
