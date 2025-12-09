/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:24:14 by memillet          #+#    #+#             */
/*   Updated: 2025/11/10 00:10:41 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putbase(unsigned long ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
		count += ft_putbase(ptr / 16);
	count += write(1, &base[ptr % 16], 1);
	return (count);
}

int	ft_printmemory(void *ptr)
{
	int		count;

	count = 0;
	if (!ptr)
		return (count = 5, write(1, "(nil)", count), count);
	count += write (1, "0x", 2);
	count += ft_putbase((unsigned long) ptr);
	return (count);
}
