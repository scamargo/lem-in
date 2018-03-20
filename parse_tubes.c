/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:51:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/19 21:57:18 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int		add_connection(int max_conn, t_room *room, t_room *adjecent)
{
	int i;

	if (!room->adjecent_rooms)
	{
		if (!(room->adjecent_rooms =
					(t_room**)ft_memalloc(sizeof(t_room*) * (max_conn + 1))))
			return (0);
	}
	i = 0;
	while (room->adjecent_rooms[i])
		i++;
	room->adjecent_rooms[i] = adjecent;
	return (1);
}

static void		free_arr(char **r_arr)
{
	free(r_arr[0]);
	free(r_arr[1]);
	free(r_arr);
}

int				parse_tubes(t_lem *meta, char *buffer, char *current_line)
{
	char	**r_arr;
	t_room	*r1;
	t_room	*r2;

	if (!current_line)
		return (0);
	while (1)
	{
		if (current_line[0] != '#')
		{
			r_arr = ft_strsplit(current_line, '-');
			if (!r_arr[0] || !r_arr[1] || r_arr[2] != 0 ||
				!ft_strcmp(r_arr[0], r_arr[1]) ||
				!get_room(meta->rooms, &r1, r_arr[0]) ||
				!get_room(meta->rooms, &r2, r_arr[1]) ||
				!add_connection(meta->number_of_rooms, r1, r2) ||
				!add_connection(meta->number_of_rooms, r2, r1))
				return (1);
			free_arr(r_arr);
		}
		free(current_line);
		if (!ft_get_line(&buffer, &current_line))
			break ;
	}
	return (1);
}
