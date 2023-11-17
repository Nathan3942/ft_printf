/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:12:45 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/17 05:09:39 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
ssize_t	convertion(const char *c, va_list *ap, size_t *i);
size_t	ft_strlen(const char *s);

ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(const char *str);
size_t	ft_putnbr(int nb);
size_t	ft_putunbr(const unsigned long nb);
size_t	ft_putvoid(void *adress);
size_t	ft_putexa_lower(const unsigned int nb);
size_t	ft_putexa_upper(const unsigned int nb);

#endif