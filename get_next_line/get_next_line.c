/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2022/12/20 17:47:04 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> */

/* void	*ft_memset(void *s, int c, size_t n)
{
	if (n > 0)
	{
		while (n--)
		{
			*(unsigned char *)(s + n) = (unsigned char)(c);
		}
	}
	return (s);
}

size_t	LineLength(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s) //Is is necessary?
{
	int	i;

	i = 0;
	while (s[i] != '\0')
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
}*/
/* 









 */
 
char	*RecreatStach(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = LineLength(s);
	if (!s[i])
	{
		free (s);
		return (0);
	}
	j = 0;
	new_s = (char *)ft_calloc(sizeof(char), (ft_strlen(s) - i + 1));
	while (s[j] != '\0')
	{
		new_s[j] = s[j];
		j++;
	}
	free (s);
	return (new_s);
}

char	*EndLine(char *s)
{
	char	*l;
	int		i;

	i = 0;
	if (!s) // = (!s[i])?
		return (0);
	l = (char *)ft_calloc(sizeof(char), (LineLength(s) + 2));
	while (s[i] != '\0' && s[i] != '\n') // not sure if \0 is necessary
	{
		l[i] = s[i];
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
		s = ft_calloc(1,1);
	t = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 1;	
	while (i != 0 && IsItTheLastLine(s) == 0)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i < 0)
		{
			free (s);
			free (t);
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
	static char *s;
	char		*l;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	l = ReadLine(s, fd);
	if (!s)
		return (0);
	l = EndLine(s);
	s = RecreatStach(s);
	return (l);
}


int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("teste.txt", O_RDONLY);
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
}
