/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:49:13 by memillet          #+#    #+#             */
/*   Updated: 2025/12/01 04:34:44 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

//fonction dans tools

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_puthex(unsigned int n, char format);
int	ft_unsigned_putnbr(unsigned int nb);

//fonction dans tools2

int	ft_printmemory(void *ptr);

//fonction dans printf

int	ft_checkpercent(const char format, va_list args);
int	ft_printf(const char *format, ...);