/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:00:10 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/15 03:26:09 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	putnbr(long nb)
{
	if (nb / 10)
		return (putnbr(nb / 10) + putnbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_putnbr(const int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		return (ft_putchar('-') + putnbr(n));
	}
	else
		return (putnbr(n));
}

size_t	ft_putunbr(const unsigned long nb)
{
	if (nb / 10)
		return (ft_putunbr(nb / 10) + ft_putunbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}
