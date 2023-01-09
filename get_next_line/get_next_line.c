/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/01/09 12:17:54 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rewrite_stash(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = line_length(s);
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	j = 0;
	new_s = ft_calloc((ft_strlen(s) - i + 1), sizeof(char));
	i++;
	while (s[i])
		new_s[j++] = s[i++];
	free (s);
	return (new_s);
}

char	*end_line(char *s)
{
	char	*l;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	l = ft_calloc((line_length(s) + 2), sizeof(char));
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

char	*last_line(char *s, int fd)
{
	char	*t;
	int		i;

	if (!s)
		s = ft_calloc(1, 1);
	t = ft_calloc ((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (is_it_the_last_line(s) == 0 && i != 0)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i == -1)
		{
			free (t);
			free (s);
			return (NULL);
		}
		t [i] = '\0';
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
	s = last_line(s, fd);
	if (!s)
		return (NULL);
	l = end_line(s);
	s = rewrite_stash(s);
	return (l);
}

/* int	main(void)
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
			break ;
		printf("Line [%02d]: %s", i, l);
		free(l);
		i++;
	}
	free (l);
	close(fd);
	return (0);
}  */
