/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:55:09 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:03 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_is_rectangular(t_game *check)
{
	int	first;
	int	next;

	first = my_strlen(check->map[check->y]);
	check->y = 0;
	while (check->map[check->y] != NULL)
	{
		check->x = 0;
		next = my_strlen(check->map[check->y]);
		if (next != first)
			return (ft_printf("map error\n"), 1);
		check->y++;
	}
	return (0);
}

int	ft_border(t_game *check)
{
	int	i;

	i = 0;
	check->x = 0;
	check->y = 0;
	if (ft_check_line(check) != 0)
		return (ft_printf("map error\n"), 1);
	check->x = 0;
	while (check->map[check->y + 1] != NULL)
		check->y++;
	if (ft_check_line(check) != 0)
		return (ft_printf("map error\n"), 1);
	while (check->map[i] != NULL)
	{
		if (check->map[i][0] != '1')
			return (ft_printf("map error\n"), 1);
		if (check->map[i][check->x - 1] != '1')
			return (ft_printf("map error\n"), 1);
		i++;
	}
	return (0);
}

int	check_element(t_game *a)
{
	a->count_P = 0;
	a->count_C = 0;
	a->count_E = 0;
	a->y = 0;
	while (a->map[a->y] != NULL)
	{
		a->x = 0;
		while (a->map[a->y][a->x] != '\n' && a->map[a->y][a->x] != '\0')
		{
			if (a->map[a->y][a->x] == 'P')
				a->count_P++;
			else if (a->map[a->y][a->x] == 'C')
				a->count_C++;
			else if (a->map[a->y][a->x] == 'E')
				a->count_E++;
			else if (a->map[a->y][a->x] != '0' && a->map[a->y][a->x] != '1' &&
					a->map[a->y][a->x] != '\n')
				return (ft_printf("map error\n"), 1);
			a->x++;
		}
		a->y++;
	}
	if (a->count_P != 1 || a->count_C < 1 || a->count_E != 1)
		return (ft_printf("map error\n"), 1);
	return (0);
}

void	flood_fill(char	**map_cpy, int y, int x)
{

	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'V' || map_cpy[y][x] == 'E' || map_cpy[y][x] == 'v')
	{
		if (map_cpy[y][x] == 'E')
			map_cpy[y][x] = 'v';	
		return ;
	}
	else
		map_cpy[y][x] = 'V';
	flood_fill(map_cpy, y, x + 1);
	flood_fill(map_cpy, y, x - 1);
	flood_fill(map_cpy, y + 1, x);
	flood_fill(map_cpy, y - 1, x);
}

int	check_flood_fill(char **map_cpy)
{
	int	x;
	int	y;

	y = 0;
	while (map_cpy[y] != NULL)
	{
		x = 0;
		while (map_cpy[y][x] != '\0' && map_cpy[y][x] != '\n')
		{
			if (map_cpy[y][x] == 'C' || map_cpy[y][x] == 'E')
				return (ft_printf("map error\n"), 1);
			x++;
		}
		y++;
	}
	return (0);	
}
