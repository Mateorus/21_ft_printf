/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:21:58 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/14 23:26:32 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strncat(char **s1, char *s2, size_t len1, size_t len2)
{
	char	*tmp;
	size_t	total_len;

	if (!len2)
		return (len1);
	total_len = len1 + len2;
	if (!(tmp = malloc(sizeof(*tmp) * (total_len + 1))))
	{
		write(2, "malloc failed\n", 14);
		exit(12);
	}
	ft_strncpy(tmp, *s1, len1);
	ft_strncpy(tmp + len1, s2, len2);
	tmp[total_len] = 0;
	free(*s1);
	*s1 = tmp;
	return (total_len);
}
