/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:02:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/14 22:08:54 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
*** PURPOSE: parse room name & ensures coordinates are valid
*/

static int	parse_room_details(t_lem *meta, char *room_text, t_room *room)
{
	size_t		arr_len;
	char		**str_arr;
	t_list		*rooms;

	str_arr = ft_strsplit(room_text, ' ');
	arr_len = 0;
	while (str_arr[arr_len])
		arr_len++;
	if (arr_len != 3)
		return (0);
	room->name = str_arr[0];
	if (!ft_stronlydigits(str_arr[1]) || !ft_stronlydigits(str_arr[2]))
		return (0);
	rooms = meta->rooms;
	while (rooms)
	{
		if (ft_strcmp(((t_room*)rooms->content)->name, room->name) == 0)
			return (0);
		rooms = rooms->next;
	}
	free(str_arr[1]);
	free(str_arr[2]);
	free(str_arr);
	return (1);
}

/*
*** TODO: ensure room names dont start with "L"
*** TODO: use enum e_room_type instead of int
*/

static int	parse_room(t_lem *meta, char *line, int type)
{
	t_room		*room;
	t_list		*new;

	if (line[0] == '#')
		return (1);
	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (0);
	if (type != 0 && type != 1 && type != 2)
		return (0);
	if (!(parse_room_details(meta, line, room)))
		return (0);
	room->type = type;
	room->visited = 0;
	room->parent = NULL;
	room->adjecent_rooms = NULL;
	new = ft_lstnew(room, sizeof(t_room));
	ft_lstadd(&meta->rooms, new);
	return (1);
}

static int	parse_room_type(char *command, bool *p_has_start, bool *p_has_end)
{
	int			room_type;

	if (ft_strcmp(command, "##start") == 0)
	{
		*p_has_start = 1;
		room_type = 1;
	}
	else
	{
		*p_has_end = 1;
		room_type = 2;
	}
	return (room_type);
}

int			is_tube(char *line)
{
	if (ft_strchr(line, '-'))
		return (1);
	return (0);
}

/*
*** Input: graph meta, ptr to input buffer, & ptr to current buffer line
*** Output: int signifying whether parsing was successfull
*/

int			parse_room_list(t_lem *meta, char **p_buffer, char **p_line)
{
	bool		has_start;
	bool		has_end;
	int			room_type;

	while (ft_get_line(p_buffer, p_line) && !is_tube(*p_line))
	{
		room_type = 0;
		if (!ft_strcmp(*p_line, "##start") || !ft_strcmp(*p_line, "##end"))
		{
			room_type = parse_room_type(*p_line, &has_start, &has_end);
			free(*p_line);
			if (!ft_get_line(p_buffer, p_line))
				return (0);
		}
		if (!parse_room(meta, *p_line, room_type))
			return (0);
		if (*p_line[0] != '#')
			meta->number_of_rooms++;
		free(*p_line);
	}
	if (!has_start || !has_end)
		return (0);
	return (1);
}
