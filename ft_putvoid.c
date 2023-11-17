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
	int	i;

	i = 0;
	if (nb / 16)
		return (putvoid(nb / 16) + putvoid(nb % 16));
	else if (!(nb / 10))
	{
		i = ft_putchar(nb + '0');
		if (i < 0)
			return (-100);
		else
			return (i);
	}
	else
	{
		i = ft_putchar((char)nb - 10 + 'a');
		if (i < 0)
			return (-100);
		else
			return (i);
	}
}

size_t	ft_putvoid(void *adress)
{
	int	temp;

	if (!adress)
		return (ft_putstr("0x0"));
	if (ft_putstr("0x") < 0)
		return (-1);
	temp = putvoid((unsigned long)adress);
	if (temp < 0)
		return (-1);
	else
		return (2 + temp);
}
