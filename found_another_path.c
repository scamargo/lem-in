/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_another_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:52:47 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/19 15:45:59 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void		add_adjecent_nodes_to_queue(t_room *room, t_queue *queue, t_room **p_exit)
{
	t_room	*curr_room;
	size_t	i;
	
	i = 0;
	while (room->adjecent_rooms[i])
	{
		curr_room = room->adjecent_rooms[i];
		if (!curr_room->parent && !curr_room->blocked && curr_room->type != 1)
		{
			curr_room->parent = room;
			if (curr_room->type == 2)
			{
				*p_exit = curr_room;
				return ;
			}
			ft_enqueue(queue, curr_room);
		}
		i++;
	}
}

static t_room	*breadth_first_search(t_lem *meta)
{
	size_t	step_count;
	t_room	*curr_room;
	t_room	*exit;
	t_queue *queue;

	step_count = 0;
	curr_room = meta->start;
	exit = NULL;
	queue = ft_queue_init();
	while (1)
	{
		add_adjecent_nodes_to_queue(curr_room, queue, &exit);
		if (exit)
			return (exit);
		if (!queue->first)
			return (NULL);
		curr_room = (t_room*)ft_dequeue(queue);
	}
}

static t_list	*build_path(t_room *room)
{
	t_list	*path;
	t_list	*head_room_node;
	t_list	*curr_room_node;

	path = NULL;
	head_room_node = NULL;
	while (room)
	{
		if(!(curr_room_node = ft_lstnew(&room, sizeof(t_room*))))
			return (NULL);
		ft_lstadd(&head_room_node, curr_room_node);
		room = room->parent;
	}
	if (!(path = ft_lstnew(head_room_node, sizeof(t_list))))
		return (NULL);
	return (path);
}

// TODO: use a path that starts at start and ends at an exit
// calc baseline
// then send ants down it
t_list			*found_another_path(t_lem *meta, size_t *baseline)
{
	t_list	*path;
	t_room	*exit;
	int		ants_on_slowest_path;
	int		number_of_paths;
	int		path_step_count;

	// BFS TO FIND PATH
	// TODO: use baseline in breadth_first_search()
	if(!(exit = breadth_first_search(meta)))
		return (NULL);
	// TODO: while building path, mark all rooms in path as blocked
	if(!(path = build_path(exit)))
		return (NULL);
	// TODO: clear parents of all rooms
	number_of_paths = 1;
	ants_on_slowest_path = (int)(meta->number_of_ants / number_of_paths); // round down on purpose
	path_step_count = 3; // add this to meta
	*baseline = ants_on_slowest_path + path_step_count - 1; // Test
	ft_printf("baseline: %i\n", *baseline);
	return (path);
}
