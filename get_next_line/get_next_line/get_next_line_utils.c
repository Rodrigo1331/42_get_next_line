/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:40:28 by rcruz-an          #+#    #+#             */
/*   Updated: 2022/12/16 17:17:16 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	FileLength(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len * sizeof(char));
	if (str == 0)
		return (0);
	while (ft_strlen(s1) > i)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	IsItTheLastLine(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	len;

	len = nmemb * size;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_memset(str, 0, len);
	return (str);
}