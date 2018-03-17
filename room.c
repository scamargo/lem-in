/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:36:17 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/16 19:02:15 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include <stdio.h>

int			init_start_room(t_lem *meta, t_room *start)
{
	if (meta->start)
	{
		perror("can't have more than one start\n");
		return (0);
	}
	start->number_of_ants = meta->number_of_ants;
	start->next_ant_in_line = 1;
	meta->start = start;
	return (1);
}

int			add_end_room(t_lem *meta, t_room *room)
{
	t_list *end_room_node;

	if (!(end_room_node = ft_lstnew(&room, sizeof(t_room*))))
		return (0);
	ft_lstadd(&meta->end_rooms, end_room_node);
	return (1);
}

int			init_room(t_room **p_room, int type)
{
	t_room	*room;

	if (!(*p_room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (0);
	room = *p_room;
	room->type = type;
	room->visited = 0;
	room->parent = NULL;
	room->adjecent_rooms = NULL;
	room->visited = false;
	room->number_of_ants = 0;
	room->next_ant_in_line = 0;
	return (1);
}
