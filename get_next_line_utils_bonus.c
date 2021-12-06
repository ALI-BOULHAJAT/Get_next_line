/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:39:10 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/12/06 17:30:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)

{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l_s[2];
	int		j;
	char	*str;

	if (s1 && s2)
	{
		l_s[0] = ft_strlen((char *)s1);
		l_s[1] = ft_strlen((char *)s2);
		str = (char *)malloc ((l_s[0] + l_s[1] + 1) * sizeof(char));
		if (!str)
		{
			free (s1);
			return (0);
		}
		j = 0;
		if ((l_s[1] + l_s[0]))
		{
			while (*s1 && l_s[0] && l_s[0]--)
				str[j++] = (char )*s1++;
			while ((*s2 && l_s[0] == 0) && l_s[1]--)
				str[j++] = (char )*s2++;
		}
		return (str[j] = 0, str);
	}
	return (0);
}

char	*re_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	str = ft_strjoin(s1, s2);
	free (s1);
	return (str);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	while (i < (count * size))
		str[i++] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l_s;
	int		i;

	l_s = ft_strlen((char *)s1);
	str = malloc((l_s + 1) * sizeof (char));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s1[i] && l_s)
	{
		str[i] = (char)s1[i];
		l_s--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
