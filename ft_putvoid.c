/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:10:06 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/17 04:25:04 by njeanbou         ###   ########.fr       */
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
	int	temp;

	if (!adress)
		return (ft_putstr("0x0"));
	if (ft_putstr("0x") == -1)
		return (-1);
	temp = putvoid((unsigned long)adress);
	if (temp < 0)
		return (-1);
	else
		return (2 + temp);
}

// size_t	ft_putvoid(void *adress)
// {
// 	unsigned long	ptr;
// 	size_t			size;
// 	int				i;
// 	unsigned char	hexdig;

// 	ptr = (unsigned long)adress;
// 	size = sizeof(void *);
// 	i = size - 1;
// 	size = 0;
// 	while (i >= 0)
// 	{
// 		hexdig = (ptr >> (i * 4)) & 0xF;
// 		if (hexdig < 10)
// 		{
// 			ft_putchar(hexdig + '0');
// 			size++;
// 		}
// 		else
// 		{
// 			ft_putchar((hexdig - 10) + 'a');
// 			size++;
// 		}
// 		i--;
// 	}
// 	return (size);
// }