/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2022/12/14 10:26:58 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ReadLine(char *s, int fd) // Read, and creat the string until it reaches \n or NULL
{
	char	*buff;
	char	*str;
	int		t;
	
	buff = (char *)malloc(sizeof((char) * BUFFER_SIZE + 1));
	t = read(fd, buff, BUFF_SIZE);
	if (!t)
	{
		free (buff);
		return (0);
	}
	

	// add null terminator
	free (buff); // probably not recommended
	return (ft_strjoin(buff, str));
}

char	*StringAfterNewLine(int fd, char t) // string after the \n or/and NULL (+2)
{
	 
	free (t);	
}

char	*EndLine(int fd, char *t) //search for \n and NULL
{
	

	
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

/* int main(void){
	int fd = "text.txt";

	printf("", get_next_line(fd))

}*/