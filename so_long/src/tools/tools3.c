/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:38:14 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:13 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	destroy_mlx(t_game *assets, int nbr)
{
	if (nbr == 1)
		mlx_destroy_image(assets->mlx_connection, assets->img_collectible);
	else if (nbr == 2)
	{
		mlx_destroy_image(assets->mlx_connection, assets->img_collectible);
		mlx_destroy_image(assets->mlx_connection, assets->img_player);
	}
	else if (nbr == 3)
	{
		mlx_destroy_image(assets->mlx_connection, assets->img_collectible);
		mlx_destroy_image(assets->mlx_connection, assets->img_player);
		mlx_destroy_image(assets->mlx_connection, assets->img_exit);
	}
	else
	{
		mlx_destroy_image(assets->mlx_connection, assets->img_collectible);
		mlx_destroy_image(assets->mlx_connection, assets->img_player);
		mlx_destroy_image(assets->mlx_connection, assets->img_exit);
		mlx_destroy_image(assets->mlx_connection, assets->img_wall);
	}
}
