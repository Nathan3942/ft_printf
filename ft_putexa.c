/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:33:13 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/17 05:02:21 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putexa_lower(const unsigned int nb)
{
	int	i;
	int	temp;

	if (nb / 16)
	{
		i = ft_putexa_lower(nb / 16);
		if (i == -1)
			return (-1);
		temp = i;
		i = ft_putexa_lower(nb % 16);
		if (i == -1)
			return (-1);
		return (temp += i);
	}
	else if (!(nb / 10))
	{
		if (ft_putchar(nb + '0') == -1)
			return (-1);
		return (1);
	}
	if (ft_putchar((char)nb - 10 + 'a') == -1)
		return (-1);
	return (1);
}

size_t	ft_putexa_upper(const unsigned int nb)
{
	int	i;
	int	temp;

	if (nb / 16)
	{
		i = ft_putexa_upper(nb / 16);
		if (i == -1)
			return (-1);
		temp = i;
		i = ft_putexa_upper(nb % 16);
		if (i == -1)
			return (-1);
		return (temp += i);
	}
	else if (!(nb / 10))
	{
		if (ft_putchar(nb + '0') == -1)
			return (-1);
		return (1);
	}
	if (ft_putchar((char)nb - 10 + 'A') == -1)
		return (-1);
	return (1);
}
