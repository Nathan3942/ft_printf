/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:33:13 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/15 02:38:29 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putexa_lower(const unsigned int nb)
{
	if (nb / 16)
		return (ft_putexa_lower(nb / 16) + ft_putexa_lower(nb % 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar((char)nb - 10 + 'a');
	return (1);
}

size_t	ft_putexa_upper(const unsigned int nb)
{
	if (nb / 16)
		return (ft_putexa_upper(nb / 16) + ft_putexa_upper(nb % 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar((char)nb - 10 + 'A');
	return (1);
}