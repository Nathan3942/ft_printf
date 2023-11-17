/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:12:27 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/17 05:11:15 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		len;
	int		temp;

	if (!str)
		return (-1);
	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			temp = convertion(str + i, &arg, &i);
		else
			temp = ft_putchar(str[i]);
		if (temp >= 0)
			len += temp;
		else
			return (-1);
		i++;
	}
	va_end(arg);
	return (len);
}

//isole le type de variable %s etc
ssize_t	convertion(const char *c, va_list *ap, size_t *i)
{
	*i += 1;
	if (*(c + 1) == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	else if (*(c + 1) == 's')
		return (ft_putstr(va_arg(*ap, const char *)));
	else if (*(c + 1) == 'p')
		return (ft_putvoid(va_arg(*ap, void *)));
	else if (*(c + 1) == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*(c + 1) == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*(c + 1) == 'u')
		return (ft_putunbr(va_arg(*ap, unsigned int)));
	else if (*(c + 1) == 'x')
		return (ft_putexa_lower(va_arg(*ap, int)));
	else if (*(c + 1) == 'X')
		return (ft_putexa_upper(va_arg(*ap, int)));
	else if (*(c + 1) == '%')
		return (ft_putchar('%'));
	else
	{
		*i -= 1;
		return (-1);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
