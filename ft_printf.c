/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:12:27 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/15 03:27:22 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	if (!str)
		return (-1);
	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += convertion(str + i, &arg);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

//isole le type de variable %s etc
size_t	convertion(const char *c, va_list *ap)
{
	size_t	len;

	len = 0;
	if (*(c + 1) == 'c')
		len += ft_putchar((char)va_arg(*ap, int));
	else if (*(c + 1) == 's')
		len += ft_putstr(va_arg(*ap, const char *));
	else if (*(c + 1) == 'p')
		len += ft_putvoid(va_arg(*ap, void *));
	else if (*(c + 1) == 'd')
		len += ft_putnbr(va_arg(*ap, int));
	else if (*(c + 1) == 'i')
		len += ft_putnbr(va_arg(*ap, int));
	else if (*(c + 1) == 'u')
		len += ft_putunbr(va_arg(*ap, unsigned int));
	else if (*(c + 1) == 'x')
		len += ft_putexa_lower(va_arg(*ap, int));
	else if (*(c + 1) == 'X')
		len += ft_putexa_upper(va_arg(*ap, int));
	else if (*(c + 1) == '%')
		len += ft_putchar('%');
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
