/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:44:10 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/25 17:54:40 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);

#endif
