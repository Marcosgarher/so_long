/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:44:58 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/17 16:27:52 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newline(char *all)
{
	int		i;
	char	*newline;

	i = 0;
	if (!all || all[0] == '\0')
		return (NULL);
	while (all[i] != '\0' && all[i] != '\n')
		++i;
	if (all[i] == '\n')
		newline = malloc((i + 2) * sizeof(char));
	else
		newline = malloc((i + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	i = 0;
	while (all[i] != '\n' && all[i] != '\0')
	{
		newline[i] = all[i];
		++i;
	}
	if (all[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

char	*ft_rest(char *rest)
{
	char	*mem;
	int		i;
	int		j;

	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		++i;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	mem = malloc((ft_strlen_gnl(rest) - i + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	++i;
	j = 0;
	while (rest[i] != '\0')
		mem[j++] = rest[i++];
	mem[j] = '\0';
	free(rest);
	return (mem);
}

char	*ft_readlines(int fd, char *rest)
{
	char	*buffer;
	int		nbyts;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nbyts = 1;
	while (!ft_strchr_gnl(rest, '\n') && nbyts != 0)
	{
		nbyts = read(fd, buffer, BUFFER_SIZE);
		if (nbyts < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbyts] = '\0';
		rest = ft_strjoin_gnl(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = ft_readlines(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_newline(rest);
	rest = ft_rest(rest);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("hola", O_RDONLY);
	i = 0;
	while (i++ < 1)
	{
		line = get_next_line(fd);
		printf("La linea: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}