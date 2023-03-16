/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:11:21 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/16 17:13:57 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	*d;
	int		i;

	if (!s)
		return (0);
	d = (char *) s;
	i = 0;
	while (d[i])
	{
		if (d[i] == (unsigned char) c)
			return (d + i);
		i++;
	}
	if (c == '\0')
		return (d + i);
	return (0);
}

char	*get_l(char *buff)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	if ((!buff) || (!buff[0]))
		return (0);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	res = (char *) malloc((i + 1) * sizeof(char));
	if (!res)
		return (0);
	j = 0;
	while (j < i)
	{
		res[j] = buff[j];
		j++;
	}
	res[j] = 0;
	return (res);
}

char	*read_buffer(char *s, int fd)
{
	int		r;
	char	*buff;

	r = 1;
	while (r && !ft_strchr(s, '\n'))
	{
		buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (0);
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
		{
			if (s)
				free(s);
			if (buff)
				free(buff);
			return (0);
		}
		buff[r] = 0;
		if (!s)
			s = ft_strdup(buff);
		else
			s = ft_strjoin(s, buff);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	s = read_buffer(s, fd);
	if (!s)
		return (0);
	temp = get_l(s);
	if (!temp)
	{
		free(s);
		s = NULL;
		return (0);
	}
	s = ft_substr(s, 0, BUFFER_SIZE);
	return (temp);
}
