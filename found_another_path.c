/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_another_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:52:47 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/16 12:24:59 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

// TODO: use a path that starts at start and ends at an exit
// calc baseline
// then send ants down it
t_list	*found_another_path(t_lem *meta, size_t *baseline)
{
	t_list	*path;
	t_list	*head_room_node;
	t_list	*current_room_node;
	t_room	*room;
	int		ants_on_slowest_path;
	int		number_of_paths;
	int		path_step_count;

	// add first room
	get_room(meta->rooms, &room, "1");
	current_room_node = ft_lstnew(&room, sizeof(t_room*));
	ft_lstadd(&head_room_node, current_room_node);
	// add next room
	get_room(meta->rooms, &room, "2");
	current_room_node = ft_lstnew(&room, sizeof(t_room*));
	ft_lstadd(&head_room_node, current_room_node);
	// add next room
	get_room(meta->rooms, &room, "4");
	current_room_node = ft_lstnew(&room, sizeof(t_room*));
	ft_lstadd(&head_room_node, current_room_node);
	// add exit 
	get_room(meta->rooms, &room, "0");
	current_room_node = ft_lstnew(&room, sizeof(t_room*));
	ft_lstadd(&head_room_node, current_room_node);
	// set baseline
	number_of_paths = 1;
	ants_on_slowest_path = (int)(meta->number_of_ants / number_of_paths); // round down on purpose
	path_step_count = 3; // add this to meta
	*baseline = ants_on_slowest_path + path_step_count - 1; // Test
	ft_printf("baseline: %i\n", *baseline);
	// create path
	path = ft_lstnew(head_room_node, sizeof(t_list*));
	return (path);
}
