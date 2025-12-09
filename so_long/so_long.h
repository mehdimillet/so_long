/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:49:43 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:47:28 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

////////////////////////////////////////////////////////////

/* ======================= */
/*         INCLUDES        */
/* ======================= */

# include <fcntl.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"

////////////////////////////////////////////////////////////

/* ======================= */
/*       	STRUCT         */
/* ======================= */

typedef struct s_game
{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		count_P;
	int		count_C;
	int		count_E;
	int		collected;
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
	int		moves;
	void	*mlx_connection;
	void	*mlx_window;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;;
	int		nbr_move;
}	t_game;

////////////////////////////////////////////////////////////

/* ======================= */
/*       	TOOLS          */
/* ======================= */

int		count_lines(int fd);
int		ft_check_line(t_game *check);
char	**map_copy(t_game *check);
int		ft_strcmp(char *s1, char *s2);
void	free_tab(char **s);
int		nbr_of_column(t_game *check);
char	*strdup(const char *s);
int		my_strlen(char *str);
void	destroy_mlx(t_game *assets, int nbr);

////////////////////////////////////////////////////////////

/* ======================= */
/*         PARSING         */
/* ======================= */

int		ft_is_rectangular(t_game *check);
int		ft_border(t_game *check);
int		check_element(t_game *check);
void	flood_fill(char	**map_cpy, int y, int x);
int		check_flood_fill(char **map_cpy);
int		check_filename(char *map_name);

////////////////////////////////////////////////////////////

/* ======================= */
/*       	PLAYER         */
/* ======================= */

void	find_player(t_game *check);
void	player_move(t_game *move, int x, int y);
int		touch_move(int	keycode, t_game	*move);

////////////////////////////////////////////////////////////

/* ======================= */
/*     INITIALISATION      */
/* ======================= */

void	load_texture(t_game *a);
void	make_texture(t_game *a);
void	call_texture(t_game *a, char c, int x, int y);
int		exit_game(t_game *a);
int		init_game(t_game *init);

////////////////////////////////////////////////////////////

/* ======================= */
/*       	MAIN           */
/* ======================= */
void	init_value(t_game *init);

#endif