/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2022/12/24 15:32:44 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;
	int		n;

	i = 0;
	n = nmemb * size;
	ptr = malloc(nmemb * size);
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
} */







char	*start_next_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = LineLength(stash);
	j = 0;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free (stash);
	return (new_stash);
}

char	*ft_each_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	line = ft_calloc((LineLength(stash) + 2), sizeof(char));
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_read_and_join(char *stash, int fd)
{
	char	*temp;
	int		count_read;

	if (!stash)
		stash = ft_calloc(1, 1);
	temp = ft_calloc ((BUFFER_SIZE + 1), sizeof(char));
	count_read = 1;
	while (IsItTheLastLine(stash) == 0 && count_read != 0)
	{
		count_read = read(fd, temp, BUFFER_SIZE);
		if (count_read == -1)
		{
			free (temp);
			free (stash);
			return (NULL);
		}
		temp [count_read] = '\0';
		stash = ft_strjoin(stash, temp);
	}
	free (temp);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_and_join(stash, fd);
	if (!stash)
		return (NULL);
	line = ft_each_line(stash);
	stash = start_next_stash(stash);
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	i = 1;
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	free (line);
	close(fd);
	return (0);
} */
