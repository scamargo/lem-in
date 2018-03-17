/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:14:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/16 23:08:43 by scamargo         ###   ########.fr       */
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

// TODO: print from the back
static void		send_ants_down_path(t_list *current_path, bool *p_all_ants_at_end)
{
	int departing_ant;
	int arriving_ant;
	t_room *curr_room;
	t_room *parent_room;
	t_list *curr_room_node;
	
	curr_room_node = (t_list*)current_path->content;
	arriving_ant = 0;
	while (curr_room_node)
	{
		curr_room = *(t_room**)curr_room_node->content;
		if (arriving_ant)
		{
			ft_printf("L%i-%s ", arriving_ant, curr_room->name);
			curr_room->number_of_ants++;
			if (curr_room->type != 2)
				*p_all_ants_at_end = false;
		}	
		if((departing_ant = curr_room->next_ant_in_line))
			curr_room->number_of_ants--;
		//ft_printf("room type: %i\n", curr_room->type);
		if (curr_room->type == 1 && curr_room->number_of_ants > 0) //make sure this will eventually set start next_in_line to zero
		{
			curr_room->next_ant_in_line++;
			*p_all_ants_at_end = false;
		}	
		else
			curr_room->next_ant_in_line = arriving_ant;
		arriving_ant = departing_ant;
		curr_room_node = curr_room_node->next;
		parent_room = curr_room;
	}
}

void			start_simulation(t_list *paths)
{
	bool	all_ants_at_end;
	t_list	*curr_path;

	all_ants_at_end = false;
	while (!all_ants_at_end)
	{
		curr_path = paths;
		all_ants_at_end = true;
		// iterate through paths
		while (curr_path)
		{
			// move ants along current path
			send_ants_down_path(curr_path, &all_ants_at_end);
			curr_path = curr_path->next;
		}
		ft_printf("\n");
	}
}

int				main(void)
{
	t_lem	*meta;
	t_list	*paths;
	t_list	*new_path;
	size_t	baseline;

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
	start_simulation(paths);
	return (0);
}
