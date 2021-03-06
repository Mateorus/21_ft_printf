/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:30:13 by gstiedem          #+#    #+#             */
/*   Updated: 2019/02/06 20:58:58 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strncpy(char *dst, char *src, int n)
{
	if (!dst || !src)
		return ;
	while (n--)
		*dst++ = *src++;
}
