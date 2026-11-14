/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selkasba <selkasba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:20:36 by selkasba          #+#    #+#             */
/*   Updated: 2026/11/14 23:26:00 by selkasba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*saved[1024];
	char		*line;
	char		*rest;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	saved[fd] = ft_read(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = ft_line(saved[fd]);
	if (!line)
		return (free(saved[fd]), saved[fd] = NULL, NULL);
	rest = ft_rest(line, saved[fd]);
	if (!rest)
		return (free(saved[fd]), free(line), saved[fd] = NULL, NULL);
	free(saved[fd]);
	saved[fd] = rest;
	if (!saved[fd][0])
	{
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (line);
}
