/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:29:15 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/19 12:58:41 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void		queue_next_ant(t_room *room, int new_ant, bool *p_ants_at_end)
{
	if (room->type == 1 && room->number_of_ants > 0)
	{
		room->next_ant_in_line++;
		*p_ants_at_end = false;
	}
	else
		room->next_ant_in_line = new_ant;
}

static void		move_ants(t_list *curr_node, bool *p_ants_at_end, char **p_out)
{
	int		departing_ant;
	int		arriving_ant;
	t_room	*curr_room;

	arriving_ant = 0;
	while (curr_node)
	{
		curr_room = *(t_room**)curr_node->content;
		if (arriving_ant)
		{
			ft_asprintf(p_out, "L%i-%s %s",
					arriving_ant, curr_room->name, *p_out);
			curr_room->number_of_ants++;
			if (curr_room->type != 2)
				*p_ants_at_end = false;
		}
		if ((departing_ant = curr_room->next_ant_in_line))
			curr_room->number_of_ants--;
		queue_next_ant(curr_room, arriving_ant, p_ants_at_end);
		arriving_ant = departing_ant;
		curr_node = curr_node->next;
	}
}

void			start_simulation(t_list *paths)
{
	bool	all_ants_at_end;
	t_list	*curr_path;
	char	*output;
	t_list	*path_head;

	all_ants_at_end = false;
	while (!all_ants_at_end)
	{
		curr_path = paths;
		all_ants_at_end = true;
		while (curr_path)
		{
			output = "";
			path_head = (t_list*)curr_path->content;
			move_ants(path_head, &all_ants_at_end, &output);
			ft_printf("%s", output);
			free(output);
			curr_path = curr_path->next;
		}
		ft_printf("\n");
	}
}
