/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:45:03 by fmaaita           #+#    #+#             */
/*   Updated: 2024/10/14 14:20:45 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	while (i < size && src[i] != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
}

char	*ft_resize(char *s)
{
	char	*temp; 
	int		i;

	temp = (char *)malloc(ft_strlen(s) + 1);
	i = -1;
	while (s[++i] != 0)
		temp[i] = s[i];
	temp[i] = '\0';
	free(s);
	s = (char *)malloc((ft_strlen(temp) * 2) + 1);
	i = -1;
	while (temp[++i] != 0)
		s[i] = temp[i];
	s[i] = '\0';
	free(temp);
	return (s);
}

int	ft_reader(char *str, char *line, int i, int fd)
{
	while (!ft_strchr(line, '\n'))
	{
		if (!str)
			return (-1);
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			str = NULL;
			return (-1);
		}
		if (i == 0)
		{
			free(str);
			break ;
		}
		str[i] = '\0';
		line = ft_resize(line);
		ft_strlcat(line, str, BUFFER_SIZE + 1);
		free(str);
		str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;
	char		*str;
	int			i;

	if (!BUFFER_SIZE)
		return (NULL);
	i = 1;
	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = ft_reader(str, line, i, fd);
	if (i == -1 || line[0] == '\0')
	{
		free(line);
		free(str);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\n')
		i++;
	ft_strlcat(save, line, i + 1);
	ft_bzero(line + i + 1);
	return (line);
}
