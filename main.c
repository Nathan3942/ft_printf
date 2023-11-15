/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:39:21 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/15 03:09:54 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main(void)
{
    void *i = "455";
    int len = 0;
    len = ft_printf("int : %p\n", i);
    printf("len : %i", len);
    return (0);
}
