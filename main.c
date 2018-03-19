/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:14:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/19 16:34:19 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include <stdio.h>

static int		parse_ants(t_lem *meta, char **p_buffer)
{
	char	*line;

	if (!ft_get_line(p_buffer, &line))
		return (0);
	if (!ft_stronlydigits(line))
		return (0);
	meta->number_of_ants = ft_atoi(line);
	if (meta->number_of_ants <= 0)
		return (0);
	free(line);
	return (1);
}

static void		read_input(t_lem *meta)
{
	char	buff[BUFF_SIZE + 1];
	int		reader;
	char	*temp;

	while ((reader = read(0, buff, BUFF_SIZE)))
	{
		buff[reader] = '\0';
		if (!meta->input)
			meta->input = ft_strdup(buff);
		else
		{
			temp = meta->input;
			meta->input = ft_strjoin(meta->input, buff);
			free(temp);
		}
	}
}

static int		parse_input(t_lem *meta)
{
	char		*buffer;
	char		*current_line;

	current_line = NULL;
	read_input(meta);
	buffer = ft_strdup(meta->input);
	if (!parse_ants(meta, &buffer))
		return (0);
	if (!parse_room_list(meta, &buffer, &current_line))
		return (0);
	if (!parse_tubes(meta, buffer, current_line))
		return (0);
	return (1);
}

int				main(void)
{
	t_lem	*meta;
	t_list	*paths;
	t_list	*new_path;

	if (!init_lem(&meta))
		return (2);
	if (!parse_input(meta))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	paths = NULL;
	while ((new_path = found_another_path(meta)))
	{
		ft_lstadd(&paths, new_path);
	}
	if (!paths)
	{
		perror("no path found");
		ft_printf("ERROR\n");
		return (2);
	}
	ft_printf("%s\n", meta->input);
	start_simulation(paths);
	return (0);
}
