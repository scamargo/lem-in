/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:21:02 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/16 19:10:40 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include <stdio.h>

int		get_room(t_list *curr_node, t_room **p_room, char *room_name)
{
	t_room	*curr_room;

	while (curr_node)
	{
		curr_room = (t_room*)curr_node->content;
		if (ft_strcmp(room_name, curr_room->name) == 0)
		{
			*p_room = curr_room;
			return (1);
		}
		curr_node = curr_node->next;
	}
	return (0);
}

int		init_lem(t_lem **p_meta)
{
	if (!(*p_meta = (t_lem*)ft_memalloc(sizeof(t_lem))))
	{
		perror("MALLOC ERROR\n");
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
