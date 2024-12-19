/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:38:30 by sozbek            #+#    #+#             */
/*   Updated: 2024/12/15 13:59:26 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_before_newline(char *buffer)
{
	char	*result;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	if (ft_newline_check(buffer))
		result = malloc(ft_newline_check(buffer) + 2);
	else
		result = malloc(ft_strlen(buffer) + 1);
	if (!result)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

static char	*ft_after_newline(char *buffer)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	result = malloc(ft_strlen(buffer) - i + 1);
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		result[j++] = buffer[i++];
	result[j] = '\0';
	free(buffer);
	return (result);
}

static char	*ft_reader(int fd, char *buffer)
{
	char	*tmp;
	int		i;

	i = 1;
	while (!ft_newline_check(buffer) && i != 0)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
			return (free(tmp), free(buffer), NULL);
		tmp[i] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		free(tmp);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_reader(fd, buffer);
	if (!buffer)
		return (NULL);
	result = ft_before_newline(buffer);
	buffer = ft_after_newline(buffer);
	return (result);
}
