/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:00:10 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/17 05:05:50 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	putnbr(long nb)
{
	int	i;
	int	temp;

	if (nb / 10)
	{
		i = ft_putunbr(nb / 10);
		if (i == -1)
			return (-1);
		temp = i;
		i = ft_putunbr(nb % 10);
		if (i == -1)
			return (-1);
		temp += i;
		return (temp);
	}
	else
	{
		if (ft_putchar(nb + '0') == -1)
			return (-1);
		else
			return (1);
	}
}

size_t	ft_putnbr(const int nb)
{
	long	n;
	int		i;

	n = nb;
	if (n < 0)
	{
		n = -n;
		i = ft_putchar('-');
		if (i == -1)
			return (-1);
		i = putnbr(n);
		if (i < 0)
			return (-1);
		return (i + 1);
	}
	else
	{
		i = putnbr(n);
		if (i < 0)
			return (-1);
		return (i);
	}
}

size_t	ft_putunbr(const unsigned long nb)
{
	int	i;
	int	temp;

	if (nb / 10)
	{
		i = ft_putunbr(nb / 10);
		if (i == -1)
			return (-1);
		temp = i;
		i = ft_putunbr(nb % 10);
		if (i == -1)
			return (-1);
		temp += i;
		return (temp);
	}
	else
	{
		if (ft_putchar(nb + '0') == -1)
			return (-1);
		else
			return (1);
	}
}
