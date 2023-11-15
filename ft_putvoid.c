/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:10:06 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/15 03:28:40 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	putvoid(const unsigned long nb)
{
	if (nb / 16)
		return (putvoid(nb / 16) + putvoid(nb % 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar((char)nb - 10 + 'a');
	return (1);
}

size_t	ft_putvoid(void *adress)
{
	if (!adress)
		return (0);
	ft_putstr("0x");
	return (2 + putvoid((unsigned long)adress));
}
