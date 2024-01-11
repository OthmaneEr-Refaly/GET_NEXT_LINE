/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:12:12 by oer-refa          #+#    #+#             */
/*   Updated: 2024/01/11 10:06:49 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*rest_str(char *str)
{
	char	*str2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	str2 = malloc(ft_strlen(str) - i + 1);
	if (str2 == NULL)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}

char	*only_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		line[j++] = str[i++];
	if (str[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*read_fd_to_buffer(char *str, int fd)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (readed != 0 && !ft_strchr(str, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		str = ft_strjoin(str, buffer);
		if (str == NULL)
			return (free(buffer), (NULL));
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*ext_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	str[fd] = read_fd_to_buffer(str[fd], fd);
	if (str[fd] == NULL)
		return (NULL);
	ext_line = only_line(str[fd]);
	str[fd] = rest_str(str[fd]);
	return (ext_line);
}
// int main()
// {
// 	int fd = open ("example.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }