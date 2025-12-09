/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:21:27 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:30:01 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stocknread(char *stock, int fd)
{
	char	*buf;
	int		bytes;

	bytes = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stock, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			if (stock)
				free (stock);
			return (NULL);
		}
		buf[bytes] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*ft_extract(char *stock)
{
	char	*line;

	line = ft_strdup(stock);
	return (line);
}

char	*ft_clean(char *stock)
{
	char	*cleanstock;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	cleanstock = malloc(sizeof(char) * (ft_strlen(stock) - i) + 1);
	if (!cleanstock)
		return (NULL);
	i++;
	while (stock[i])
		cleanstock[j++] = stock[i++];
	cleanstock[j] = '\0';
	free(stock);
	return (cleanstock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0)
		free(stock);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_stocknread(stock, fd);
	if (!stock)
		return (NULL);
	line = ft_extract(stock);
	stock = ft_clean(stock);
	return (line);
}
