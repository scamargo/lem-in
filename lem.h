/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:17:39 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/19 12:30:02 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H

# define LEM_H

# include "libft.h"
# include <stdbool.h>

/*
 *** TODO: add enum for room_type
*/

typedef struct	s_room
{
	char			*name;
	int				type;
	struct s_room	**adjecent_rooms;
	struct s_room	*parent;
	bool			visited;
	int				number_of_ants;
	int				next_ant_in_line;
}				t_room;

typedef struct	s_lem
{
	t_list			*rooms;
	int				number_of_ants;
	t_list			*valid_paths;
	unsigned int	baseline_turns;
	char			*input;
	unsigned		number_of_rooms;
	t_room			*start;
	t_list			*end_rooms;
}				t_lem;

int				parse_room_list(t_lem *meta, char **p_buffer, char **p_line);
int				parse_tubes(t_lem *meta, char *buffer, char *current_line);
int				get_room(t_list *curr_node, t_room **p_room, char *room_name);
t_list			*found_another_path(t_lem *meta, size_t *baseline);
int				init_room(t_room **p_room, int type);
int				init_start_room(t_lem *meta, t_room *start);
int				add_end_room(t_lem *meta, t_room *room);
int				init_lem(t_lem **p_meta);
void			start_simulation(t_list *paths);

#endif
