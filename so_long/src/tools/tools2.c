/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:43:35 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:12 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_tab(char **s)
{
	int	j;

	j = 0;
	if (!s)
		return ;
	while (s[j])
		free(s[j++]);
	free(s);
}

int	nbr_of_column(t_game *check)
{
	int	y;

	y = 0;
	while (check->map[y] != NULL)
		y++;
	return (y);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	*strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*strdup(const char *s)
{
	const char	*dest;

	dest = malloc (my_strlen((char *)s) * sizeof (char) + 1);
	if (dest == NULL)
		return (NULL);
	strcpy ((char *)dest, (char *)s);
	return ((char *)dest);
}
