/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2022/12/16 18:44:12 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*RecreatStach(char *s) // recreat malloc and free the old stach
{
	char	*new_stash;
	int		i;
	int		j;
	
	
	free (t);	
}

char	*EndLine(char *s) //search for \n && NULL
{
	int	len;
	int	i;

	i = 0;
	//len = ft_strlen(char *s)
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ReadLine(char *s, int fd) // Read and concatenate the string until it reaches \n
{
	char	*t;
	int		i;
	
	if (!s)
		s = ft_calloc(1,1);
	t = (char *)malloc(sizeof((char) * (BUFFER_SIZE + 1))); //calloc or malloc?
	i = 1;	
	while (i != 0 && IsItTheLastLine(s) == 0) //Ask Juliana for some help :)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i < 0)
		{
			free (s);
			free (t);
			return (0);
		}
		t[i] = '\0';
		s = ft_strjoin(s, temp);
	}
	free (temp);
	return (s);
}

char	*get_next_line(int fd)
{
	static char *s;
	char		l;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	l = ReadLine(s, fd);
	if (!s)
		return (0);


}

/*
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
}*/