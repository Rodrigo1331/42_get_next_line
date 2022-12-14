/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2022/12/14 15:22:48 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*RecreatBuff(int fd, char t) // recreat malloc and free the old stach
{
	char	*new_stash;
	int		i;
	int		j;
	
	
	free (t);	
}

char	*EndLine(int fd, char *t) //search for \n and NULL
{
	int	len;
	int	i;

	i = 0;
	//len = ft_strlen(char *t)
	while (t[i] != '\0' && t[i] != '\n')
		i++;
	return (i);
}

char	*ReadLine(char *s, int fd) // Read and concatenate the string until it reaches \n or NULL
{
	char	*buff;
	char	*str;
	int		t;
	
	s = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	buff = (char *)malloc(sizeof((char) * BUFFER_SIZE + 1));
	t = read(fd, buff, BUFF_SIZE);
	if (!t)
	{
		free (s);
		free (buff);
		return (0);
	}
	if (endline(int fd, char *s) == BUFFER_SIZE) //probably not ok


	// add null terminator
	free (buff); // probably not recommended
	return (ft_strjoin(buff, str));
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