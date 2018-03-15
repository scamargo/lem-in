/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:14:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/14 22:21:20 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int		get_room(t_list *current_node, t_room **p_matching_room, char *room_name)
{
	t_room	*room;

	while (current_node)
	{
		room = (t_room*)current_node->content; 
		if (ft_strcmp(room_name, room->name) == 0)
		{
			*p_matching_room = room;
			return (1);
		}
		current_node = current_node->next;
	}
	return (0);
}

static int		add_connection(int max_connections, t_room *room, t_room *adjecent)
{
	int i;

	if (!room->adjecent_rooms)
	{
		if (!(room->adjecent_rooms = (t_room**)ft_memalloc(sizeof(t_room*) * max_connections)))
			return (0);
	}
	i = 0;
	while (room->adjecent_rooms[i])
		i++;
	room->adjecent_rooms[i] = adjecent;
	return (1);
}

static int		parse_tubes(t_lem *meta, char *buffer, char *current_line)
{
	char	**rooms_arr;
	t_room	*room1;
	t_room	*room2;

	if (!current_line)
		return (0);
	while(ft_get_line(&buffer, &current_line))
	{
		if (current_line[0] != '#')
		{
			rooms_arr = ft_strsplit(current_line, '-');
			if (!rooms_arr[0] || !rooms_arr[1] || rooms_arr[2] != 0)
				return (1);
			if (!ft_strcmp(rooms_arr[0], rooms_arr[1]))
				return (1);
			if (!get_room(meta->rooms, &room1, rooms_arr[0]))
				return (1);
			if (!get_room(meta->rooms, &room2, rooms_arr[1]))
				return (1);
			if (!add_connection(meta->number_of_rooms, room1, room2))
				return (1);
			add_connection(meta->number_of_rooms, room2, room1);
		}
	}
	return (1);
}

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
	if(!parse_tubes(meta, buffer, current_line))
		return (0);
	t_room	*room;
	room = (t_room*)meta->rooms->content;
	ft_printf("connections; %s->%s\n", room->name, ((t_room**)room->adjecent_rooms)[0]->name);
	// TODO: should this second one be failing??
	ft_printf("connections; %s->%s\n", room->name, ((t_room**)room->adjecent_rooms)[1]->name);
	return (1);
}

int				main(void)
{
	t_lem	*meta;

	if (!(meta = (t_lem*)ft_memalloc(sizeof(t_lem))))
	{
		ft_printf("MALLOC ERROR\n");
		return (2);
	}
	meta->rooms = NULL;
	meta->number_of_ants = 0;
	meta->valid_paths = NULL;
	meta->baseline_turns = 0;
	meta->input = NULL;
	meta->number_of_rooms = 0;
	if (!parse_input(meta))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	ft_printf("%s\n", meta->input);
	return (0);
}
