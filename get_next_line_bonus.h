/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:42:30 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/12/06 16:43:22 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*re_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_read(int fd, char *s);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
#endif