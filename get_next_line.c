/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selkasba <selkasba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:20:36 by selkasba          #+#    #+#             */
/*   Updated: 2026/11/14 20:14:37 by selkasba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *saved)
{
	ssize_t	r;
	char	*buffer;
	char	*joined;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(saved), NULL);
	while (!ft_strchr(saved, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
			return (free(buffer), saved);
		if (r < 0)
			return (free(saved), free(buffer), NULL);
		buffer[r] = '\0';
		joined = ft_strjoin(saved, buffer);
		if (!joined)
			return (free(saved), free (buffer), NULL);
		free(saved);
		saved = joined;
	}
	free(buffer);
	return (saved);
}

char	*ft_line(char *saved)
{
	size_t	i;
	char	*line;

	if (!saved || saved[0] == '\0')
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_rest(char *line, char *saved)
{
	char	*rest;
	size_t	i;

	if (!saved || !line)
		return (NULL);
	i = 0;
	while (line[i])
		i++;
	rest = malloc(ft_strlen(saved) - i + 1);
	if (!rest)
		return (NULL);
	ft_strcpy(rest, saved + i);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	char		*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = ft_read(fd, saved);
	if (!saved)
		return (NULL);
	line = ft_line(saved);
	if (!line)
		return (free(saved), saved = NULL, NULL);
	rest = ft_rest(line, saved);
	if (!rest)
		return (free(saved), free(line), saved = NULL, NULL);
	free(saved);
	saved = rest;
	return (line);
}
