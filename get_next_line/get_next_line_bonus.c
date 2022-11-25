/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:49:40 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/25 17:58:08 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include "get_next_line.h"

static char	*verificar_quebra_de_linha(int fd, char *stash)
{
	char	*p_lidos;
	int		b_lidos;
	char	*tmp;

	p_lidos = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	b_lidos = 42;
	while (b_lidos != 0 && !(ft_strchr(p_lidos, '\n')))
	{
		b_lidos = read(fd, p_lidos, BUFFER_SIZE);
		if (b_lidos < 0)
		{
			if (stash)
				free (stash);
			free (p_lidos);
			return (NULL);
		}
		*(p_lidos + b_lidos) = '\0';
		tmp = ft_strjoin(stash, p_lidos);
		free (stash);
		stash = tmp;
	}
	free (p_lidos);
	return (stash);
}

static char	*linha_limpa(char *stash)
{
	int		i;
	char	*linha;

	i = 0;
	if (!(*(stash + i)))
	{
		return (NULL);
	}
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
		i++;
	linha = malloc(sizeof(char) * (i + 1 + 1));
	if (!linha)
		return (NULL);
	i = 0;
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
	{
		*(linha + i) = *(stash + i);
		i++;
	}
	*(linha + i) = *(stash + i);
	i++;
	*(linha + i) = '\0';
	return (linha);
}

static char	*coletar_lixo(char *stash)
{
	int		i;
	int		j;
	char	*lixo;

	i = 0;
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
		i++;
	if (!(*(stash + i)) || !stash)
	{
		free (stash);
		return (NULL);
	}
	lixo = ft_calloc(sizeof(char), (ft_strlen(stash) - i));
	printf("%s", lixo);
	i++;
	j = 0;
	while (*(stash + i) != '\0')
	{
		*(lixo + j++) = *(stash + i++);
	}
	free (stash);
	return (lixo);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_F_OPEN];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash[fd] = verificar_quebra_de_linha(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = linha_limpa(stash[fd]);
	stash[fd] = coletar_lixo(stash[fd]);
	return (line);
}
