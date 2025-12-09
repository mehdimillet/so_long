/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:59:52 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:11 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int count_lines(int fd)
{
    char *line;
    int count;

    count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        count++;
        free(line);
    }
    return (count);
}

int	ft_check_line(t_game *check)
{
	check->x = 0;
	while (check->map[check->y][check->x] != '\0' &&
			check->map[check->y][check->x] != '\n')
	{
		if (check->map[check->y][check->x] != '1')
			return (1);
		check->x++;
	}
	return (0);
}

char **map_copy(t_game *check)
{
    char **map_cpy;
    int y;

    y = 0;
    while (check->map[y] != NULL)
        y++;
    map_cpy = malloc(sizeof(char *) * (y + 1));
    if (!map_cpy)
        return (NULL);
    y = 0;
    while (check->map[y] != NULL)
    {
        map_cpy[y] = strdup(check->map[y]);
        if (!map_cpy[y])
            return (NULL);
        y++;
    }
    map_cpy[y] = NULL;
    return (map_cpy);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
