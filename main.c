/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:14:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/13 09:41:21 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "stdio.h"

int		ft_get_line(char **p_buffer, char **p_line)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = ft_strchr(*p_buffer, '\n')))
	{
		*new = '\0';
		new++;
		*p_line = *p_buffer;
		*p_buffer = ft_strdup(new);
		return (1);
	}
	*p_line = *p_buffer;
	*p_buffer = NULL;
	if (**p_line)
		return (1);
	ft_strdel(p_line);
	return (0);
}

int		parse_ants(t_lem *meta, char **p_buffer) // TODO: make sure the ants is only numbers
{
	char	*line;

	if (!ft_get_line(p_buffer, &line))
		return (0);
	meta->number_of_ants = ft_atoi(line);
	if (meta->number_of_ants <= 0)
		return (0);
	free(line);
	return (1);
}

char	*parse_room_name(char *room_info)
{
	size_t	len;
	char	*result;

	len = 0;
	while (room_info[len] && room_info[len] != ' ')
		len++;
	result = ft_strndup(room_info, len);
	// TODO: validate coordinates
	return (result);
}

int		parse_room(t_lem *meta, char *line, int type) // TODO: use enum room_type instead of int
{

	t_room	*room;
	t_list	*new;

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

int		parse_room_list(t_lem *meta, char **p_buffer) // TODO: return 1 if hit tube
{
	char	*line;
	bool	has_start;
	bool	has_end;

	has_start = 0;
	has_end = 0;
	while (ft_get_line(p_buffer, &line))
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			free(line);
			if (!ft_get_line(p_buffer, &line))
				return (0);
			if (!parse_room(meta, line, 1))
				return (0);
			has_start = 1;
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			free(line);
			if(!ft_get_line(p_buffer, &line))
				return (0);
			if (!parse_room(meta, line, 2))
				return (0);
			has_end = 1;
		}
		else if (line[0] != '#')
		{
			if (!parse_room(meta, line, 0))
				return (0);
		}
		free(line);
	}
	if (!has_start || !has_end)
		return (0);
	return (1);
}


int		parse_input(t_lem *meta)
{
	char		buff[BUFF_SIZE + 1];
	int			reader;
	char		*temp;
	char		*buffer;

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
	buffer = ft_strdup(meta->input);
	if (!parse_ants(meta, &buffer))
		return (0);
	if (!parse_room_list(meta, &buffer))
		return (0);
	/*if (!parse_tubes(meta))
		return (0);*/
	return (1);
}

int		main(void)
{
	t_lem	*meta;

	if (!(meta = (t_lem*)ft_memalloc(sizeof(t_lem))))
	{
		ft_printf("MALLOC ERROR\n");
		return (2);
	}
	meta->rooms = NULL;
	meta->number_of_ants = 0;
	meta->valid_paths = NULL;
	meta->baseline_turns = 0;
	meta->input = NULL;
	if (!parse_input(meta))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	ft_printf("%s\n", meta->input); // TODO: use ft_ft_printf
	return (0);
}
