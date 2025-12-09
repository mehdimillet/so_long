/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:25:09 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:09 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	find_player(t_game *check)
{
	int	y;
	int	x;

	y = 0;
	while (check->map[y] != NULL)
	{
		x = 0;
		while (check->map[y][x] != '\0' && check->map[y][x] != '\n')
		{
			if (check->map[y][x] == 'P')
			{
				check->pos_x = x;
				check->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	feur(t_game	*move, int new_x, int new_y)
{
	call_texture(move, '0', move->pos_x, move->pos_y);
	move->pos_x = new_x;
	move->pos_y = new_y;
	call_texture(move, 'P', new_x, new_y);
	move->nbr_move++;
	ft_printf("Mouvements: %u\n", move->nbr_move);
}

void	player_move(t_game *move, int y, int x)
{
	int	new_x;
	int	new_y;

	new_x = move->pos_x + x;
	new_y = move->pos_y + y;
	if (move->map[new_y][new_x] == '1')
		return ;
	else if (move->map[new_y][new_x] == 'C')
	{
		move->count_C--;
		move->map[new_y][new_x] = '0';
	}
	else if (move->map[new_y][new_x] == 'E')
	{
		if (move->count_C == 0)
		{
			ft_printf("Victoire!\n");
			exit_game(move);
		}
		else
			return ;
	}
	feur(move, new_x, new_y);
}

int	touch_move(int keycode, t_game *move)
{
	if (keycode == 65362 || keycode == 'w')
		player_move(move, -1, 0);
	else if (keycode == 65364 || keycode == 's')
		player_move(move, 1, 0);
	else if (keycode == 65361 || keycode == 'a')
		player_move(move, 0, -1);
	else if (keycode == 65363 || keycode == 'd')
		player_move(move, 0, 1);
	else if (keycode == 65307)
		exit_game(move);
	return (0);
}