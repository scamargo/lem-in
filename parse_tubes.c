/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:51:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/15 17:22:32 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int		add_connection(int max_connections, t_room *room, t_room *adjecent)
{
	int i;

	if (!room->adjecent_rooms)
	{
		if (!(room->adjecent_rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (max_connections + 1))))
			return (0);
	}
	i = 0;
	while (room->adjecent_rooms[i])
		i++;
	room->adjecent_rooms[i] = adjecent;
	return (1);
}

int				parse_tubes(t_lem *meta, char *buffer, char *current_line)
{
	char	**rooms_arr;
	t_room	*room1;
	t_room	*room2;

	if (!current_line)
		return (0);
	while(1)
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
		if(!ft_get_line(&buffer, &current_line))
			break;
	}
	return (1);
}
