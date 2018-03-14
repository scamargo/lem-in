/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:02:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/13 20:04:30 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
 *** TODO: validate coordinates
*/

static char	*parse_room_name(char *room_info)
{
	size_t	len;
	char	*result;

	len = 0;
	while (room_info[len] && room_info[len] != ' ')
		len++;
	result = ft_strndup(room_info, len);
	return (result);
}

/*
 *** TODO: use enum e_room_type instead of int
*/

static int	parse_room(t_lem *meta, char *line, int type)
{
	t_room	*room;
	t_list	*new;

	if (line[0] == '#')
		return (1);
	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (0);
	if (type != 0 && type != 1 && type != 2)
		return (0);
	if (!(room->name = parse_room_name(line)))
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
	int room_type;

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

/*
 *** TODO: figure out if you are calling ft_get_line redundantly
 *** TODO: return (1) if you hit a tube
*/

int			parse_room_list(t_lem *meta, char **p_buffer)
{
	char	*line;
	bool	has_start;
	bool	has_end;
	int		room_type;

	while (ft_get_line(p_buffer, &line))
	{
		room_type = 0;
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		{
			room_type = parse_room_type(line, &has_start, &has_end);
			free(line);
			if (!ft_get_line(p_buffer, &line))
				return (0);
		}
		if (!parse_room(meta, line, room_type))
			return (0);
		free(line);
	}
	if (!has_start || !has_end)
		return (0);
	return (1);
}
