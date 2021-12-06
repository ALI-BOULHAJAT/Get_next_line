/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:54:31 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/12/06 17:38:21 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_read(int fd, char *s)
{
	char	*buf;
	int		retur;

	if (!s)
		s = ft_strdup("");
	while (!ft_strchr(s))
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		retur = read(fd, buf, BUFFER_SIZE);
		if (retur < 0)
		{
			free (buf);
			return (NULL);
		}
		if (retur == 0)
		{
			free(buf);
			break ;
		}
		s = re_strjoin(s, buf);
		free (buf);
	}	
	return (s);
}

char	*ft_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	if (!str[j])
		return (NULL);
	while (str[j] && str[j] != '\n')
		j++;
	line = (char *)malloc(j + 2);
	i = 0;
	while (str[i] && str[i] != '\n' )
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_back_str(char *s)
{
	int		i;
	int		j;
	char	*reste;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free (s);
		return (NULL);
	}
	i++;
	reste = malloc((ft_strlen(s) - i) + 1);
	while (s[i])
	{
		reste[j] = s[i];
		j++;
		i++;
	}
	free (s);
	reste[j] = '\0';
	return (reste);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	s = ft_read(fd, s);
	line = ft_line(s);
	s = ft_back_str(s);
	return (line);
}
