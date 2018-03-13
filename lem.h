/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:17:39 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/12 18:35:46 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H

# define LEM_H

# include "libft.h"
# include <stdbool.h>

// TODO: add enum for room_type

typedef struct	s_room
{
	char			*name;
	int				type;
	t_list			*adjecent_rooms;
	struct s_room	*parent;
	bool			visited;
}				t_room;

typedef struct	s_lem
{
	t_list			*rooms;
	int				number_of_ants;
	t_list			*valid_paths;
	unsigned int	baseline_turns;
	char			*input;
}				t_lem;

#endif
