/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:49:28 by memillet          #+#    #+#             */
/*   Updated: 2025/11/28 02:46:21 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkpercent(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_printmemory(va_arg(args, void *)));
	if (format == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_unsigned_putnbr(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 'x'));
	if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 'X'));
	if (format == '%')
		return (count = 1, ft_putchar('%'), count);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	va_start(args, format);
	i = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_checkpercent(format[i + 1], args);
			i++;
		}
		else
			count += write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	d;
// 	int	count;
// 	int	reelcount;
// 	d = -21483648;
// 	count = ft_printf("ft_printf: %d\n", d);
// 	reelcount = printf("le printf: %d\n", d);
// 	printf ("count mon printf %d && count vrais printf %d\n",count, reelcount);
// 	return (0);
// }