/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:46:44 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/01/09 12:35:08 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*s[FOPEN_MAX];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	s[fd] = last_line(s[fd], fd);
	if (!s[fd])
		return (NULL);
	l = end_line(s[fd]);
	s[fd] = rewrite_stash(s[fd]);
	return (l);
}

/* int main()
{
	int fd1;
	int fd2;
	char *ptr;
	char *ptr2;
	fd1 = open("text.txt", O_RDONLY);
	ptr = get_next_line(fd1);
	printf("%s", ptr);
	free(ptr);
	fd2 = open("text2.txt", O_RDONLY);
	ptr2 = get_next_line(fd2);
	printf("%s", ptr2);
	free(ptr2);
	ptr = get_next_line(fd1);
	printf("%s", ptr);
	free(ptr);
	ptr2 = get_next_line(fd2);
	printf("%s", ptr2);
	free(ptr2);
	close(fd1);
	close(fd2);
	return (0);
} */