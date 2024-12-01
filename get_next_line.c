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

void	ft_shift(char s[], int i)
{
	int	counter;

	counter = 0;
	while (s[counter + i] != '\0')
	{
		s[counter] = s[counter + i];
		counter++;
	}
	s[counter] = '\0';
}

int	ft_reader(char save[], char *str, int i, int fd)
{
	while (!ft_strchr(save, '\n'))
	{
		str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!str)
			return (-1);
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			str = NULL;
			return (i);
		}
		if (i == 0)
		{
			free(str);
			break ;
		}
		str[i] = '\0';
		ft_strlcat(save, str, BUFFER_SIZE + 1);
		free(str);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	save[100000];
	char		*str;
	int			i;

	if (!BUFFER_SIZE)
		return (NULL);
	i = 1;
	str = NULL;
	i = ft_reader(save, str, i, fd);
	if (i == -1 || save[0] == '\0')
	{
		save[0] = '\0';
		return (NULL);
	}
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strlcpy(str, save, i + (save[i] == '\n') + 1);
	ft_shift(save, i + (save[i] == '\n'));
	return (str);
}
