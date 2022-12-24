/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2022/12/24 15:06:13 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;
	int		n;

	i = 0;
	n = nmemb * size;
	ptr = (char *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (n-- > 0)
		ptr[i++] = '\0';
	return (ptr);
}

int	IsItTheLastLine(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	LineLength(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
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
	str = (char *)malloc(len * sizeof(char));
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


char	*RecreatStash(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = LineLength(s);
	if (!s[i])
	{
		free(s);
		return (0);
	}
	j = 0;
	new_s = (char *)ft_calloc(sizeof(char), (ft_strlen(s) - i + 1));
	i++;
	while (s[i])
		new_s[j++] = s[i++];
	free (s);
	return (new_s);
}


char	*EndLine(char *s)
{
	char	*l;
	int		i;

	i = 0;
	if (!s[i])
		return (0);
	l = (char *)ft_calloc((LineLength(s) + 2), sizeof(char));
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		l[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		l[i] = '\n';
	return (l);
}

char	*ReadLine(char *s, int fd)
{
	char	*t;
	int		i;

	if (!s)
		s = ft_calloc(1, 1);
	t = (char *)ft_calloc ((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (IsItTheLastLine(s) == 0 && i != 0)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i < 0)
		{
			free (t);
			free (s);
			return (0);
		}
		t[i] = '\0';
		s = ft_strjoin(s, t);
	}
	free (t);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s = ReadLine(s, fd);
	if (!s)
		return (NULL);
	l = EndLine(s);
	s = RecreatStash(s);
	return (l);
}

int	main(void)
{
	char	*l;
	int		i;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	i = 1;
	while (fd)
	{
		l = get_next_line(fd);
		if (!l)
			break;
		printf("line [%02d]: %s", i, l);
		free(l);
		i++;
	}
	free (l);
	close(fd);
	return (0);
}