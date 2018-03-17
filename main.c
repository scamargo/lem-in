/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:14:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/16 15:24:12 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

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

static int		init_lem(t_lem **p_meta)
{
	if (!(*p_meta = (t_lem*)ft_memalloc(sizeof(t_lem))))
	{
		ft_printf("MALLOC ERROR\n");
		return (0);
	}
	(*p_meta)->rooms = NULL;
	(*p_meta)->number_of_ants = 0;
	(*p_meta)->valid_paths = NULL;
	(*p_meta)->baseline_turns = 0;
	(*p_meta)->input = NULL;
	(*p_meta)->number_of_rooms = 0;
	(*p_meta)->start = NULL;
	(*p_meta)->end_rooms = NULL;
	return (1);
}

int				main(void)
{
	t_lem	*meta;
	t_list	*paths;
	t_list	*new_path;
	size_t	path_index;
	size_t	baseline;

	path_index = 0; // JUST FOR TESTING
	if (!init_lem(&meta))
		return (2);
	if (!parse_input(meta))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	baseline = 0;
	// TODO: remove two lines below
	new_path = found_another_path(meta, &baseline);
	ft_lstadd(&paths, new_path);
	/*while ((new_path = found_another_path(meta, &baseline)))
	{
		ft_lstadd(&paths, new_path);
	}*/
	ft_printf("%s\n", meta->input);
	//send ants down each path
	/*bool all_ants_at_end = false;
	while (!all_ants_at_end)
	{
		path_index = 0;
		// iterate through paths
		while (paths[path_index])
		{
			// move ants along current path
			send_ants_down_path(meta, paths[path_index++], &all_ants_at_end);
		}
		ft_printf("\n");
	}*/
	return (0);
}
