/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:53:30 by fmaaita           #+#    #+#             */
/*   Updated: 2024/10/12 17:41:46 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

char    *ft_strchr(const char *s, int c)
{
        while (*s)
        {
                if (*s == (char)c)
                        return ((char *)s);
                s++;
        }
        if ((char)c == '\0')
                return ((char *)s);
        return (NULL);
}

void	ft_bzero(void *str)
{
	unsigned char	*temp;

	if (!str)
		return ;
	temp = (unsigned char *)str; 
	while (*temp != 0)
	{
		*temp = 0;
		temp++;
	}
}
