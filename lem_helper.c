/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:21:02 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/16 18:54:19 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

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
