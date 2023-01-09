/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:46:44 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/01/09 12:41:27 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FOPEN_MAX
#  define FOPEN_MAX 1024
# endif

char	*last_line(char *s, int fd);
char	*end_line(char *s);
char	*rewrite_stash(char *s);
char	*get_next_line(int fd);

int		is_it_the_last_line(const char *s);
size_t	line_length(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
#endif