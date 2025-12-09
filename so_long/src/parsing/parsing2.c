/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:12:48 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:07 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_filename(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4 || ft_strcmp(&map_name[len - 4], ".ber") != 0)
		return (ft_printf("wrong file extension\n"), 1);
	return (0);
}
