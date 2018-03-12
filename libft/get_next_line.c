/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:35:38 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/12 13:10:39 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(const int fd, char **str_arr, char **line)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = ft_strchr(str_arr[fd], '\n')))
	{
		*new = '\0';
		new++;
		*line = str_arr[fd];
		str_arr[fd] = ft_strdup(new);
		return (1);
	}
	*line = str_arr[fd];
	str_arr[fd] = NULL;
	if (**line)
		return (1);
	ft_strdel(line);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char *str_arr[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	int			reader;
	char		*temp;

	if (line == NULL || fd < 0 || read(fd, buff, 0) < 0 || fd > MAX_FD)
		return (-1);
	while ((reader = read(fd, buff, BUFF_SIZE)))
	{
		buff[reader] = '\0';
		if (!str_arr[fd])
			str_arr[fd] = ft_strdup(buff);
		else
		{
			temp = str_arr[fd];
			str_arr[fd] = ft_strjoin(str_arr[fd], buff);
			free(temp);
		}
	}
	if (!reader && !str_arr[fd])
	{
		*line = NULL;
		return (0);
	}
	return (get_line(fd, str_arr, line));
}
